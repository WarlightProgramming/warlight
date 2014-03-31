#ifndef SUPERREGION__H_
#define SUPERREGION__H_

#include <vector>
#include "Region.h"

class SuperRegion {
 private:
    int _id;
    int _value;
    std::vector<Region> _regions;
 public:
    SuperRegion(const int id, const int value);
    void addRegion(const Region & region);
    const std::vector<Region> & regions() const;
    int id() const;
    int value() const;
};


#endif // SUPERREGION__H_
