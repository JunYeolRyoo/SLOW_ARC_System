#ifndef PITCH_TRACKER_H_
#define PITCH_TRACKER_H_

#include <iostream>
#include <fstream>
#include "PitchRepresentation.h"

/*
Description: This class' primary function is to initialize a data structure that will serve as a representation of the path of a ball in a pitch.
*/
class PitchTracker{
  public:
    /*
    Description: This constructor is used to initialize the data in a data structure representation of a pitch.
    Parameters:
      - csv_file_name: Type string. This parameter is the name of the file in the current input feed that is to be used to produce to set the value of pitch_representation.
      - pitch_representation: Type PitchRepresentation. This parameter is an uninitialize variable which this class will populate with the appropriate data.
    */
    PitchTracker(std::string csv_file_name, PitchRepresentation *pitch_representation);
};

#endif
