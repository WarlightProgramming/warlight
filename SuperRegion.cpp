#include "SuperRegion.h"

SuperRegion::SuperRegion(const int id, const int value):_id(id), _value(value), _regions() {}

void SuperRegion::addRegion(const Region & region) {
    _regions.push_back(region);
}

const std::vector<Region> & SuperRegion::regions() const {return _regions;}

int SuperRegion::id() const {return _id;}
int SuperRegion::value() const {return _value;}
