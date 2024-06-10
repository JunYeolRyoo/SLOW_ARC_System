//Done by Fuad
#include <iostream>
#include "../include/HomePlateRepresentation.h"
#include "../include/HomePlateTracker.h"

//Coordinate default constructor
Coordinate::Coordinate() {
    this->x = 0.0;
    this->y = 0.0;
}
Coordinate::Coordinate(double valX, double valY) {
    this->x = valX;
    this->y = valY;
}

// Default constructor
Homeplate::Homeplate() {}

// Getter for coordinate vector
const std::vector<Coordinate>& Homeplate::getCoordinates() const {
    return coordinates;
}

// Setter for coordinates
void Homeplate::addCoordinate(Coordinate coordinate) {
    this->coordinates.push_back(coordinate);
}