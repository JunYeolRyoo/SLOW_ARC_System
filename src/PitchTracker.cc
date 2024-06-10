#include "../include/PitchTracker.h"

PitchTracker::PitchTracker(std::string csv_file_name, PitchRepresentation *pitch_representation){
  std::ifstream ip(csv_file_name);
  if (!ip.is_open()){
    std::cout << "Can't open csv file\n";
    exit(-1);
  }
  for (int i = 0; i < 9; ++i) {
    std::string tmp_line;
    std::getline(ip, tmp_line);
  }

  int index = 0;
  std::string time_stamp;
  std::string center_x_coordinate;
  std::string center_y_coordinate;
  std::string left_x_coordinate;
  std::string left_y_coordinate;
  std::string right_x_coordinate;
  std::string right_y_coordinate;
  while (ip.peek()!=EOF){
    std::getline(ip, time_stamp, ',');
    std::getline(ip, center_x_coordinate, ',');
    std::getline(ip, center_y_coordinate, ',');
    std::getline(ip, left_x_coordinate, ',');
    std::getline(ip, left_y_coordinate, ',');
    std::getline(ip, right_x_coordinate, ',');
    std::getline(ip, right_y_coordinate, '\n');
    pitch_frame_t frame;
    frame.time_stamp = std::stoi(time_stamp);
    frame.center[0] = std::stoi(center_x_coordinate);
    frame.center[1] = std::stoi(center_y_coordinate);
    frame.left[0] = std::stoi(left_x_coordinate);
    frame.left[1] = std::stoi(left_y_coordinate);
    frame.right[0] = std::stoi(right_x_coordinate);
    frame.right[1] = std::stoi(right_y_coordinate);
    pitch_representation->add_frame(index++, frame);
  }
  
}