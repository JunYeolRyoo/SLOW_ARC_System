#ifndef PR_H_
#define PR_H_

#include <unordered_map>
#include <iostream>

/*
Description: This struct will serve as a basic building block of our data structure that will become a representation of the path of the ball or pitch.
*/
typedef struct {
  int time_stamp;
  int center[2];
  int left[2];
  int right[2];
} pitch_frame_t;

/*
Description: This class' primary function is to create and return a custom data structure that will represent the path of a ball in a pitch.
*/
class PitchRepresentation {
  private:
    /*
    Description: This private field will store the coordianate vector that will serve as the representation of the pitch.
    */
    std::unordered_map<int, pitch_frame_t> pitch_data;
  
  
  public:
    /*
    Description: This method takes a frame of data from the current input from the feed and adds it to the private field pitch_data.
    Parameters: 
      - frame: Type pitch_frame_t. This parameter is the value which will be appended into the pitch_data private field.
      - index: This int paramater will be the index of the frame when it is added to pitch_data
    Return: Void
    */
    void add_frame(int index, pitch_frame_t frame);
  
  
    /*
    Description: This method method is used to get a single frame from the pitch_data private field.
    Parameters: 
      - index: Type int. This parameter will be used to find the pitch frame with with the index equal to the value passed to this parameter.
    Return: This method returns a frame of the pitch of type pitch_frame_t.
    */
    pitch_frame_t get_frame(int index);
  
    
    /*
    Description: This method is used as a getter for the pitch_data private field.
    Parameters: None
    Return: This method returns the private field pitch_data of type unordered_map
    */
    std::unordered_map<int, pitch_frame_t> get_pitch_data();
};

#endif
