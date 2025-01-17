#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include "VariantWrapper.hpp"

#include <string>
#include <unordered_map>
#include <vector>

//TK: also define ItemId
using ItemId = int;
using Key = std::string;
using Value = VariantWrapper<std::string, int, double>;
using Map = std::unordered_map<Key, Value>;
using CommandInfo = std::pair<std::string, Map>;

using Coord = std::pair<double, double>; //TK: call this Point
using BoundingBox = std::pair<Coord, Coord>; //TK: you can simply call this Rect

struct CommandTemplate {
    std::string commandName;
    std::vector<std::vector<Key> > mandatoryKeys;
    std::vector<std::vector<Key> > optionalKeys;
};

namespace defs {
    std::string toStr(Value val);
    double toDouble (Value val);
    int toInt (Value val);
}

#endif // DEFINITIONS_HPP