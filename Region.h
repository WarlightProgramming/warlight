#ifndef REGION__H_
#define REGION__H_

#include <vector>

enum bot_name {BOT_US, BOT_THEM, BOT_NEUTRAL, BOT_UNKNOWN};

class Region {
 private:
    int _id;
    bot_name _owner;
    int _armies;
    std::vector<int> _neighbours;
 public:
    Region(const int id);
    Region(const int id, const bot_name owner, const int armies);
    void addNeighbour(const int id);
    const std::vector<int> & neighbours () const;
    int id() const;
    bot_name owner() const;
    int armies() const;
    void updateOwner(const bot_name o);
    void updateArmies(const int a);
};

#endif // REGION__H_
