#ifndef HOMEPLATEREPRESENTATION_H
#define HOMEPLATEREPRESENTATION_H

#include <vector>
#include <initializer_list>

/*
Description: This struct will serve as a basic building block of our data structure that will become a representation of the home plate.
*/
struct Coordinate {
    double x;
    double y;
    //default constructor
    Coordinate();
    //constructor for coordinate with values
    Coordinate(double xVal, double yVal); 
};

/*
Description: This class' primary function is to create and return a custom data structure that will represent the home plate in a pitch.
*/
class Homeplate {
private:
    /*
    Description: This private field will store the coordianate vector that will serve as the representation of the home plate.
    */
    std::vector<Coordinate> coordinates;
    
public:
    /*
    Description: This is the defauld constructor for this class.
    Parameters: None
    */ 
    Homeplate();

    /*
    Description: This method is used as a getter for the coordinates private field.
    Parameters: None
    Return: Returns the coordinates private field of type vector<Coordinate>.
    */
    const std::vector<Coordinate>& getCoordinates() const;

    
    /*
    Description: This method creates a coordinate of (valX, valY) and saves it in vector array of Homeplate. valX and valY are doubles for coordinates. 
    Parameters: 
        - coordinate: Type Coordinate. This parameter is the value which will be appended into the coordinates private feild. valX and valY are doubles for coordinates.
    Return: Void
    */
    void addCoordinate(Coordinate coordinate);
};

#endif // HOMEPLATEREPRESENTATION_H

