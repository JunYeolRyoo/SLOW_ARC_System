//Done by Fuad

/*Tracker class:
    (a) attributes: Has a Batter Representation in private variable
    (b) function: Read CSV file and sets it in this->Batter Representation object
        | the indexing follows the order of the CSV file
    (c) function: returns this-> Batter Representation
*/
#include <string>

#ifndef BATTERTRACKER_H
#define BATTERTRACKER_H
#include "../include/HomePlateRepresentation.h"
#include "../include/BatterRepresentation.h"

/*
Description: This class' primary function is to produce a data structure that will serve as a representation of the batter.
*/
class BatterTracker {
private:
    /*
    Description: This private field will serve as the representation of the batter that will provide the primary functionality of the class.
    Type: BatterRep
    */
    BatterRep Tbatter; 
    
    /*
    Description: This private field is used to be able to ensure that the private field homeplate can only be set once, 
    which will prevent the occurence of errors.
    Type: int
    */
    int flag = 0;
    
    
public:
    /*
    Description: This is the default constructor for the BatterTracker class.
    Parameters: None
    */
    BatterTracker();

    
    /*
    Description: This method creates a home plate representation using the CSV file stored in the feed and stores that value in the Tbatter private field.
    Parameters: 
        - filename: This is a string that contains the file path to the CSV file that will be used to set the value of the private feild homeplate.
    Return: Returns 1 if successful and 0 if errors occur.
    */
    int CreateBatterCSV(std::string filename);
    
    
    /*
    Description: This method is an alternative setter for the Tbatter private feild that sets Tbatter using a pre-initialized parameter of type of BatterRep.
    Parameters: 
        - batter: This parameter is of type BatterRep and is the value that will be set to the Tbatter private feild.
    Return: Void
    */
    void CreateBatterParam(BatterRep batter);
    
    
    /*
    Description: This method returns the representation of the batter stored in the Tbatter private feild. Index of Tbatter[i] corresponds 
    to the order in which it is in the CSV file.
    Parameters: None
    Return: Homeplate
    */
    BatterRep GetBatter();

};

#endif // BATTERTRACKER_H

