#ifndef BOT__H_
#define BOT__H_

#include <iostream>
#include <string>

#include "Map.h"
#include "StateMachine.h"

class Bot {
 private:
    Map _map;
    StateMachine _stateMachine;
    std::istream & _in;
    std::string _name;
    int _armiesPerTurn;

    void settings();
    void setupMap();
    void pickStartingRegions();
    void update();
    void opponentMoves();
    void go();
 public:
    Bot(std::istream & in);
    void run();
};

#endif // BOT__H_
