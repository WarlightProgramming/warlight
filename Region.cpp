#include "Region.h"

Region::Region(const int id):_id(id), _owner(BOT_NEUTRAL), _armies(2), _neighbours() {}

Region::Region(const int id, const bot_name owner, const int armies):
    _id(id), _owner(owner), _armies(armies), _neighbours() {}

void Region::addNeighbour(const int id) {
    _neighbours.push_back(id);
}

const std::vector<int> & Region::neighbours() const {return _neighbours;}
int Region::id() const {return _id;}
int Region::armies() const {return _armies;}
bot_name Region::owner() const {return _owner;}
void Region::updateOwner(const bot_name o) {_owner = o;}
void Region::updateArmies(const int a) {_armies = a;}
