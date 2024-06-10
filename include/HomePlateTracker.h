//Done by Fuad

/*Tracker class:
    (a) attributes: Has a Homeplate Representation in private variable
    (b) function: Read CSV file and sets it in this->Homeplate Representation object
        | the indexing follows the order of the CSV file
    (c) function: returns this-> Homeplate Representation
*/
#include <string>

#ifndef HOMEPLATETRACKER_H
#define HOMEPLATETRACKER_H
#include "../include/HomePlateRepresentation.h"

/*
Description: This class' function is to use the data provided from the feed singleton to produce a representation of the home plate.
*/
class HomeplateTracker {
private:
    /*
    Description: This private field will serve as the representation of homeplate that will provide the primary functionality of the class.
    Type: Homeplate
    */ 
    Homeplate homeplate; 
    
    /*
    Description: This private field is used to be able to ensure that the private field homeplate can only be set once, 
    which will prevent the occurence of errors.
    Type: int
    */
    int flag = 0;
    
public:
    /*
    Description: This is the default constructor.
    Parameters: None
    */
    HomeplateTracker();
    
    
    /*
    Description: This method creates a home plate representation using the CSV file stored in the feed and stores that value in the homeplate private field.
    Parameters: 
        - filename: This is a string that contains the file path to the CSV file that will be used to set the value of the private field homeplate.
    Return: Returns 1 if successful and 0 if errors occur.
    */
    int CreateHomeplateCSV(std::string filename);
    
    
    /*
    Description: This method is an alternative setter for the homeplate private field that sets homeplate using a pre-initialized type of Homeplate.
    Parameters: 
        - plate: This parameter is of type Homeplate and is the value that will be set to the homeplate private field.
    Return: Void
    */
    void CreateHomeplateParam(Homeplate plate);
    
    
    /*
    Description: This method returns the representation of the homeplate stored in the homeplate private field. Index of homeplate[i] corresponds 
    to the order in which it is in the CSV file.
    Parameters: None
    Return: Homeplate
    */
    Homeplate GetHomeplate();
};

#endif // HOMEPLATETRACKER_H
