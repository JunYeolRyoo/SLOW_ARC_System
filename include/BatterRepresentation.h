//Done by Fuad
#ifndef BATTERREPRESENTATION_H
#define BATTERREPRESENTATION_H

#include <vector>
#include "../include/HomePlateRepresentation.h"

/*
Description: This class is a custom data structure that will serve as a representation for the batter.
*/
class BatterRep {
private:
    /*
    Description: This private field holds the values that represent the batter as a datasructure.
    Type: vector<Coordinate>
    */
    std::vector<Coordinate> coordinates;
    
public:
    /*
    Description: This is the default constructor for the BatterRep class.
    Parameters: None
    */
    BatterRep();

    
    /*
    Description: This method returns the vector of coordinates which make up the representation of the batter.
    Parameters: None
    Return: vector<Coordinate>
    */
    const std::vector<Coordinate>& getCoordinates() const;

    
    /*
    Description: This method creates a coordinate of (valX, valY) and saves it in vector array of BatterRep. valX and valY are doubles for coordinates. 
    Parameters: 
        - coordinate: Type Coordinate. This parameter is the value which will be appended into the coordinate private field. valX and valY are doubles for coordinates.
    Return: Void
    */
    void addCoordinate(Coordinate coordinate);
};

#endif // BATTERREPRESENTATION_H
