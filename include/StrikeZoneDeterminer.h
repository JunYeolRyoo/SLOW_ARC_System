#ifndef SZD_H_
#define SZD_H_
#include "StrikeZoneRepresentation.h"
#include "HomePlateRepresentation.h"
#include "HomePlateTracker.h"
#include "BatterTracker.h"
#include "BatterRepresentation.h"
#include "Feed.h"
#include <string>

/*
Description: This class' main function is to use the feed to produce a representation of the strike zone.
*/
class StrikeZoneDeterminer {
    private:
        /*
        Description: This private field is used to get a data structure representation of the of the home plate which will be used in determining the strike zone
        Type: HomePlateTracker
        */
        HomeplateTracker homePlate;
        
        /*
        Description: This private field is used to store a data structure representation of the of the batter which will be used in determining the strike zone
        Type: BatterRepresentation
        */
        BatterRep batterRep;
    
        /*
        Description: This private field is used to store a data structure representation of the of the home plate which will be used in determining the strike zone
        Type: HomePlateTracker
        */
        Homeplate homeRep;

        BatterTracker BatterTrack;

    public:
        /*
        Description: This is the constructor for the StrikeZoneDeterminer() class
        Parameters: None
        */
        StrikeZoneDeterminer();
    
    
        /*
        Description: This method returns a data structure that serves as a representation of the strike zone.
        Parameters: None
        Retrun: StrikeZoneRepresentation
        */
        StrikeZoneRepresentation* find_strikezone();

        BatterTracker get_batter_track(){return this->BatterTrack;}
};

#endif
