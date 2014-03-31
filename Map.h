#ifndef MAP__H_
#define MAP__H_

#include <vector>
#include "SuperRegion.h"
#include "Region.h"
enum bot_name;

class Map {
 private:
    std::vector<Region> _regions;
    std::vector<SuperRegion> _superRegions;
 public:
    Map() {}
    void addRegion(const int id, const bot_name owner, const int armies, const int superRegion);
    void addSuperRegion(const int id, const int value);
    void connectRegions(const int first, const int second);
    void updateRegion(int id, bot_name owner, int armies);
    friend std::ostream & operator<<(std::ostream & out, const Map & map);

    const std::vector<Region> & regions() const;
    const std::vector<SuperRegion> & superRegions() const;
    Region & region(const int id);
    SuperRegion & superRegion(const int id);
};

#endif //MAP__H_
