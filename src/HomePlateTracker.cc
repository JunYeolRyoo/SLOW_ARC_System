//Done by Fuad
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/HomePlateRepresentation.h"
#include "../include/HomePlateTracker.h"

//Class HomeplateTracker: Default Constructor 
HomeplateTracker::HomeplateTracker(){};

//Creates homeplate from a homeplate object
void HomeplateTracker::CreateHomeplateParam(Homeplate plate){
    this->flag = 1;
    this->homeplate = plate;
};

//Creates homeplate using CSV file
int HomeplateTracker::CreateHomeplateCSV(std::string filename){
    while (this->flag == 0){
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return 0;
        }
        std::string line;
        int line_count = 0;

        while (getline(file, line) && line_count < 5) {
            std::stringstream ss(line);
            std::string value1;
            std::string value2;

            getline(ss, value1, ',');
            getline(ss, value2, ',');

            double xVal = std::stod(value1);
            double yVal = std::stod(value2);

            Coordinate input(xVal, yVal);
            this->homeplate.addCoordinate(input);
            line_count++;
        }
        //Successful
        this->flag = 1;
        return 1;
    }
    std::cerr << "Homeplate has already been set once and cannot be modified again" << std::endl;
    return 0;
};

Homeplate HomeplateTracker::GetHomeplate(){
    return this->homeplate;
};
