#include "../include/StrikeZoneDeterminer.h"

StrikeZoneDeterminer::StrikeZoneDeterminer(){
     homePlate = HomeplateTracker();
    batterRep = BatterRep();
    BatterTrack = BatterTracker();
    homeRep = Homeplate();
}

StrikeZoneRepresentation* StrikeZoneDeterminer::find_strikezone(){
    Feed* feed = Feed::getInstance();
    std::string PathCurFeed;

    PathCurFeed = feed -> get_curr_feed(); 

    std::vector<Coordinate> Homeplate_coordinates;
    std::vector<Coordinate> Batter_coordinates;

    if(PathCurFeed.length() != 0){ // Check PathCurfeed is not empty
        if(homePlate.CreateHomeplateCSV(PathCurFeed)){ // CreateHomeplateCSV
            Homeplate_coordinates = homePlate.GetHomeplate().getCoordinates();  // Get coordinates for homeplate
        }
        if(BatterTrack.CreateBatterCSV(PathCurFeed)){ // CreateBatterCSV
            Batter_coordinates = BatterTrack.GetBatter().getCoordinates();  // Get coordinates for batter
        }  
    }

    StrikeZoneRepresentation* Strikezone = new StrikeZoneRepresentation();  // Dynamically allocate StrikeZoneRepresentation


    std::vector<int> smallestXpoint = {9999,9999};  // For storing point having smallest x value among 5 points of homeplate
    std::vector<int> biggestXpoint = {0,0};         // For storing point having largest x value among 5 points of homeplate

    // After getting each coordinates of homeplate, append each of them to homeplate attribute of StrikeZoneRepresentation
    // Also getting two points with smallest x value and biggest x value for deciding strike zone
    for(Coordinate c : Homeplate_coordinates){
        std::vector<int> singlePoint;
        singlePoint.push_back(static_cast<int>(c.x));
        singlePoint.push_back(static_cast<int>(c.y));

        Strikezone->homeplate.push_back(singlePoint);   // Append the coordinate to homeplate attribute

        if(singlePoint.at(0) < smallestXpoint.at(0)) smallestXpoint = singlePoint;
        if(singlePoint.at(0) > biggestXpoint.at(0)) biggestXpoint = singlePoint;
    }


    Coordinate big,small;
    std::vector<int> point;

    // Move batter to homeplate for calculating strike zone. If batter's left shoulder's x value is smaller than right shoulder's
    // x value, set batter's left shoulder's x value equal to smallestXpoint from home plate and vice versa.
    if(Batter_coordinates.at(0).x < Batter_coordinates.at(1).x){
        small = Batter_coordinates.at(0);
        big = Batter_coordinates.at(1);
    }else{
        small = Batter_coordinates.at(1);
        big = Batter_coordinates.at(0);
    }
    // Make first point for strike zone and append it to strikezone
    point.push_back(smallestXpoint.at(0));
    point.push_back(static_cast<int>(small.y));
    Strikezone->strikezone.push_back(point);
    point.clear();

    // Make second point for strike zone and append it to strikezone
    point.push_back(biggestXpoint.at(0));
    point.push_back(static_cast<int>(big.y));
    Strikezone->strikezone.push_back(point);
    point.clear();

    if(Strikezone->strikezone.at(0).at(1) > Strikezone->strikezone.at(1).at(1)) Strikezone->strikezone.at(1).at(1) = Strikezone->strikezone.at(0).at(1);
    else Strikezone->strikezone.at(0).at(1) = Strikezone->strikezone.at(1).at(1);

    // Move batter to homeplate for calculating strike zone. If batter's left knee's x value is smaller than right knee's x value,
    // set batter's left knee's x value equal to smallestXpoint from home plate and vice versa.
    if(Batter_coordinates.at(2).x < Batter_coordinates.at(3).x){
        small = Batter_coordinates.at(2);
        big = Batter_coordinates.at(3);
    }else{
        small = Batter_coordinates.at(3);
        big = Batter_coordinates.at(2);
    }

    // Make third point for strike zone and append it to strikezone
    point.push_back(biggestXpoint.at(0));
    point.push_back(static_cast<int>(big.y));
    Strikezone->strikezone.push_back(point);
    point.clear();

    // Make last point for strike zone and append it to strikezone
    point.push_back(smallestXpoint.at(0));
    point.push_back(static_cast<int>(small.y));
    Strikezone->strikezone.push_back(point);
    point.clear();

    if(Strikezone->strikezone.at(2).at(1)<Strikezone->strikezone.at(3).at(1))   Strikezone->strikezone.at(3).at(1) = Strikezone->strikezone.at(2).at(1);
    else Strikezone->strikezone.at(2).at(1) = Strikezone->strikezone.at(3).at(1);

    return Strikezone;
}
