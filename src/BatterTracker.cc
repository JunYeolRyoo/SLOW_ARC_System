//Done by Fuad
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/HomePlateRepresentation.h"
#include "../include/BatterTracker.h"

//Class Batter Tracker: Default Constructor 
BatterTracker::BatterTracker(){};

//Creates Batter from a batter object
void BatterTracker::CreateBatterParam(BatterRep batter){
    if(this->flag == 0){
        if (batter.getCoordinates().size() == 4){
        this->flag = 1;
        this->Tbatter = batter;
        }
        else{
        std::cerr << "Error: Parameter has more than 4 sets of Coordinates. Failed to construct batter object." << std::endl;
        }
    }
    else{
        std::cerr << "Error: Batter already initialized once." << std::endl;
    }
    
};
//Creates homeplate using CSV file
int BatterTracker::CreateBatterCSV(std::string filename){
    while (this->flag == 0){
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return 0;
        }
        std::string line;
        int line_count = 0;

        //do nothing for the first 5 lines
        while (getline(file, line) && line_count < 4){
            line_count++;
        }

        while (getline(file, line) && line_count < 8) {
            std::stringstream ss(line);
            std::string value1;
            std::string value2;

            getline(ss, value1, ',');
            getline(ss, value2, ',');

            double xVal = std::stod(value1);
            double yVal = std::stod(value2);

            Coordinate input(xVal, yVal);
            this->Tbatter.addCoordinate(input);
            line_count++;
        }
        //Successful
        this->flag = 1;
        return 1;
    }
     std::cerr << "Error: Batter already initialized once." << std::endl;
            return 0;
};

BatterRep BatterTracker::GetBatter(){
    return this->Tbatter;
};
//Done by Fuad
