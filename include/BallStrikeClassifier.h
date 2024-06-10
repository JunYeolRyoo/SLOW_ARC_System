#ifndef BALLSTRIKECLASSIFIER_H_
#define BALLSTRIKECLASSIFIER_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Feed.h"
#include "StrikeZoneRepresentation.h"
#include "PitchRepresentation.h"
#include "StrikeZoneDeterminer.h"
#include "PitchTracker.h"


/*
Description: This class' primary function is to determine if a pitch is a ball or strike from the representations of the strike zone and the pitch,
and return a boolean value based off of the logic it uses to make that determination.
*/
class BallStrikeClassifier {
    private:
	/*
	Description: This private field is used to get a representation of the strike zone to be used in determining if the ball passes through the strike zone.
	Type: StrikeZoneDeterminer
	*/
        StrikeZoneDeterminer* s_zone_det;
	
	/*
	Description: This private field is used to get a representation of the pitch to be used in determining if the ball passes through the strike zone.
	Type: PitchTracker
	*/
	PitchTracker* pitch_tracker;
	
	/*
	Description: This private field is where the representation of the strike zone will be stored when returned from the s_zone
	object, which will then be used to determin if the ball passes through the strike zone.
	Type: StrikeZoneRepresentation
	*/
	StrikeZoneRepresentation* s_zone;
	
	/*
	Description: This private field is where the representation of the pitch will be stored when returned from the pitch_tracker
	object, which will then be used to determin if the ball passes through the strike zone.
	Type: PitchRepresentation
	*/
	PitchRepresentation* pitch;

    public:
	/*
	Description: Constructor for the BallStrikeClassifier() class
	Parameters: None
	*/
	BallStrikeClassifier();
	
	
	/*
	Description: This method is used to return a boolean representation of if the ball passed through the strike zone.
	Parameters: string
	Return: boolean
	*/
	bool pass_through_strikezone(std::string filename);
	
	
	/*
	Description: This method is used to return a boolean representation of wether or not the pitch can be classified as a ball or strike.
	Parameters: string
	Return: boolean
	*/
	bool classify_ball_strike(std::string filename);
};

#endif
