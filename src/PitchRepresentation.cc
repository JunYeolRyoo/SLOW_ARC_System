#include "../include/PitchRepresentation.h"

void PitchRepresentation::add_frame(int index, pitch_frame_t frame){
  pitch_data[index] = frame;
}

pitch_frame_t PitchRepresentation::get_frame(int index){
  try{
    return this->pitch_data.at(index);
  }
  catch (const std::out_of_range& e) {
    throw std::out_of_range("Key not found in pitch_data");
  }
}

std::unordered_map<int, pitch_frame_t> PitchRepresentation::get_pitch_data(){
  return this->pitch_data;
}