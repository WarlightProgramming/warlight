#include <iostream>

#include "Map.h"
#include "Region.h"
#include "SuperRegion.h"

void Map::addRegion(const int id, const bot_name owner, const int armies, const int superID) {
    Region r(id, owner, armies);
    _regions.push_back(r);
    if (superID) superRegion(superID).addRegion(region(id));
}

void Map::addSuperRegion(const int id, const int value) {
    SuperRegion r(id, value);
    _superRegions.push_back(r);
}

Region & Map::region(const int id) {
    for (Region & r: _regions) {
	if (r.id() == id) return r;
    }

    Region r(id, BOT_UNKNOWN, 2);
    _regions.push_back(r);
    return region(id);
}

SuperRegion & Map::superRegion(const int id) {
    for (SuperRegion & s: _superRegions) {
	if (s.id() == id) return s;
    }

    SuperRegion s(id, 0);
    _superRegions.push_back(s);
    return superRegion(id);
}

void Map::connectRegions(const int first, const int second) {
    region(first).addNeighbour(second);
    region(second).addNeighbour(first);
}

const std::vector<Region> & Map::regions() const {return _regions;}
const std::vector<SuperRegion> & Map::superRegions() const {return _superRegions;}

void Map::updateRegion(int id, bot_name owner, int armies) {
    for (Region r: _regions) {
	if (r.id() == id) {
	    r.updateOwner(owner);
	    r.updateArmies(armies);
	}
    }
}

std::ostream & operator<<(std::ostream & out, const Map & map) {
    out << "Printing map...\n";
    for (Region r: map._regions) {
	out << r.id() << ((r.owner() == BOT_US) ? "us" : "them") << r.armies() << '\n';
    }
    return out;
}

