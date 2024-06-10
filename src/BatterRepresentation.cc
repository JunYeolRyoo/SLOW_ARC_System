//Done by Fuad
#include <iostream>
#include "../include/HomePlateRepresentation.h"
#include "../include/BatterRepresentation.h"

// Default constructor
BatterRep::BatterRep() {}

// Getter for coordinate vector
const std::vector<Coordinate>& BatterRep::getCoordinates() const {
    return this->coordinates;
}

// Setter for coordinates 
// one Coordinate at a time
void BatterRep::addCoordinate(Coordinate coordinate) {
    this->coordinates.push_back(coordinate);
}
