#ifndef SZR_H_
#define SZR_H_
#include <vector>

/*
Description: This class is a custom data structure that will represent the strike zone.
*/
class StrikeZoneRepresentation {
    public:
        /*
        Description: This vector holds the values that represent the strike zone.
        */
        std::vector<std::vector<int>> strikezone; 
    
        /*
        Description: This vector holds the values that represent the home plate.
        */
        std::vector<std::vector<int>> homeplate;
};

#endif

