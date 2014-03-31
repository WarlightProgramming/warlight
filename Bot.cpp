#include "Bot.h"
#include <sstream>
#include <string>

Bot::Bot(std::istream & in):_map(), _stateMachine(), _in(in) {}

void Bot::run() {
    std::string command;
    while (_in >> command) {
        if (command == "settings") settings();
	else if (command == "setup_map") setupMap();
	else if (command == "pick_starting_regions") pickStartingRegions();
	else if (command == "update_map") update();
	else if (command == "go") {
	    std::string stage;
	    _in >> stage;
	    if (stage == "place_armies") _stateMachine.place(_map);
	    else if (stage == "attack/transfer") _stateMachine.move(_map);
	}
	else if (command == "print") std::cout << _map << std::endl;
    }
}

void Bot::settings() {
    std::string param;
    _in >> param;
    if (param == "your_bot") _in >> _name;
    else if (param == "opponent_bot") _in >> param; //waste it
    else _in >> _armiesPerTurn;
}

void Bot::setupMap() {
    std::string param;
    _in >> param;
    if (param == "super_regions") {
	int id;
	int value;
	std::string line;
	std::getline(_in, line);
	std::stringstream ss(line);
	while (ss >> id >> value) {
	    _map.addSuperRegion(id, value);
	}
    } else if (param == "regions") {
	int id;
	int parent;
	std::string line;
	std::getline(_in, line);
	std::stringstream ss(line);
	while (ss >> id >> parent) {
	    _map.addRegion(id, BOT_NEUTRAL, 2, parent);
	}
    } else if (param == "neighbours") {
	int id;
	std::string input_neighbours;
	std::vector<int> neighbours;
	while (_in >> id >> input_neighbours) {
	    for (unsigned int i = 0; i < input_neighbours.length(); ++i) {
		if (i % 2 == 0) {
		    int n = input_neighbours[i] - '0';
		    neighbours.push_back(n);
		}
	    }

	    for (int i: neighbours) {
		_map.connectRegions(id, i);
	    }
	}
    }
}

void Bot::update() {
    std::string line;
    std::getline(_in, line);
    std::stringstream ss(line);
    int id;
    std::string owner;
    int armies;
    while (ss >> id >> owner >> armies) {
	if (owner == _name) _map.updateRegion(id, BOT_US, armies);
	else _map.updateRegion(id, BOT_THEM, armies);
    }
    _stateMachine.update(_map);
}

void Bot::pickStartingRegions() {
    std::cout << "PICKING!!!!\n";
}
