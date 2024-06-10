#include "../include/BallStrikeClassifier.h"
#include "../include/matplotlibcpp.h" 

BallStrikeClassifier::BallStrikeClassifier(){}

bool BallStrikeClassifier::classify_ball_strike(std::string filename) {
  this->s_zone_det = new StrikeZoneDeterminer();
  this->pitch = new PitchRepresentation();
  Feed* feed = Feed::getInstance();
  std::string curr_feed = feed->get_curr_feed();
  this->pitch_tracker = new PitchTracker(curr_feed, this->pitch);
  this->s_zone = this->s_zone_det->find_strikezone();
  std::vector<int> x_point;
  std::vector<int> y_point;
  for(std::vector<int> c: this->s_zone->homeplate){
      x_point.push_back(c.at(0));
      y_point.push_back(c.at(1));
  }

  x_point.push_back(x_point.at(0));
  y_point.push_back(y_point.at(0));
  matplotlibcpp::plot(x_point,y_point,"r-");

  x_point.clear();
  y_point.clear();
  std::vector<Coordinate> c = this->s_zone_det->get_batter_track().GetBatter().getCoordinates();

  for(int i=0; i<4; i++){
    x_point.push_back(c.at(i).x);
    y_point.push_back(c.at(i).y);
  }
  
  matplotlibcpp::plot(x_point,y_point,"kx");

  x_point.clear();
  y_point.clear();

  for(std::vector<int> c : this->s_zone->strikezone){
    x_point.push_back(c.at(0));
    y_point.push_back(c.at(1));
  }
  x_point.push_back(x_point.at(0));
  y_point.push_back(y_point.at(0));
  matplotlibcpp::plot(x_point,y_point,"r-");
  matplotlibcpp::ylim(350,3); 
  return pass_through_strikezone(filename);
}

bool BallStrikeClassifier::pass_through_strikezone(std::string filename) {
  // find x_min and x_max of the strikezone
  double x_min = (((this->s_zone)->strikezone).at(0)).at(0);
  double x_max = (((this->s_zone)->strikezone).at(0)).at(0);
  for (int i = 1; i < 4; i++) {
    double tmp_val = (((this->s_zone)->strikezone).at(i)).at(0);
    x_min = std::min(x_min, tmp_val);
    x_max = std::max(x_max, tmp_val);
  }
  // filter the pitch frames for the relevant ones
  std::vector<int> relevant_frames;
  relevant_frames.push_back(-1);
  pitch_frame_t curr_frame;
  std::unordered_map<int, pitch_frame_t> map = this->pitch->get_pitch_data();
  int max_index = map.size();

  std::vector<int> x_point;
  std::vector<int> y_point;
  for(int i=0; i<max_index; i++){
    pitch_frame_t curr = this->pitch->get_frame(i);
    x_point.push_back(curr.left[0]);
    y_point.push_back(curr.left[1]);
    x_point.push_back(curr.center[0]);
    y_point.push_back(curr.center[1]);
    x_point.push_back(curr.right[0]);
    y_point.push_back(curr.right[1]);
    matplotlibcpp::plot(x_point,y_point,"b.");
    matplotlibcpp::pause(0.2);  
    x_point.clear();
    y_point.clear();
  }

  int cross_xmin = -1;
  int cross_xmax = -1;
  for (int i = 0; i < max_index; i++) {
    curr_frame = this->pitch->get_frame(i);
    double center_x = curr_frame.center[0];
    if (center_x >= x_min) {
      if (cross_xmin == -1) cross_xmin = i;
      if (center_x <= x_max) relevant_frames.push_back(i);
      if (center_x > x_max && cross_xmax == -1) cross_xmax = i;
    }
  }
  if (relevant_frames.size() == 1) {
    relevant_frames.clear();
    if (cross_xmin == -1) {  // accounts for pitches like example no.9
      relevant_frames.push_back(max_index - 2);
      relevant_frames.push_back(max_index - 1);
    } else {
      relevant_frames.push_back(cross_xmin - 1);  // case where one pitch left of strikezone,
      relevant_frames.push_back(cross_xmin);      // one to the right but none inside bounds
    }
  } else {  // at least one frame inside the strikezone's x boundary
    relevant_frames.at(0) = relevant_frames.at(1) - 1;
    int temp = relevant_frames.at(relevant_frames.size() - 1);
    if ((temp + 1) < max_index) {
      relevant_frames.push_back(temp + 1);
    }
  }
  // check if the ball's depth is correctly inside strikezone
  // Find the average diameter of the ball in the relevant pitch frames
  double avg_relevant_diameter = 0;
  if (cross_xmin == -1) {
    avg_relevant_diameter = std::abs(
        (this->pitch->get_frame(relevant_frames.at(relevant_frames.size() - 1))
             .right[0]) -
        (this->pitch->get_frame(relevant_frames.at(relevant_frames.size() - 1))
             .left[0]));
  } else {
    avg_relevant_diameter =
        std::abs(this->pitch->get_frame(cross_xmin - 1).right[0] -
                 this->pitch->get_frame(cross_xmin - 1).left[0]);
  }
  // find the edges of the homeplate to compare the ratios
  std::vector<std::vector<int>> hp = (this->s_zone)->homeplate;
  double close_plate_edge = hp.at(1).at(0) - hp.at(0).at(0);
  double far_plate_edge = hp.at(3).at(0) - hp.at(4).at(0);
  if (close_plate_edge < 0) {
    close_plate_edge = -close_plate_edge;
  }
  if (far_plate_edge < 0) {
    far_plate_edge = -far_plate_edge;
  }
  // return false if depth is not within the strikezone's depth
  // standard 12-inch softball had diameter 3.82 inches
  double ball_ratio = avg_relevant_diameter / 3.82;
  double min_ratio = far_plate_edge / 8.5;
  double max_ratio = close_plate_edge / 8.5;
  std::string printstr = "Verdict for pitch in ";
  printstr += filename;

  if ((ball_ratio < min_ratio || ball_ratio > max_ratio) || cross_xmin == -1) {
    printstr += ": BALL!";
    matplotlibcpp::text(10, 25, printstr);
    matplotlibcpp::show();
    return false;
  }else{    // ball's depth is within strikezone, so further checking needed in this case
            // always at least two 'relevant frames' that can be the sole focus
            // of the logic
            // calculate y upper-boundary (y = m1x + c1)
    std::vector<std::vector<int>> szr = this->s_zone->strikezone;
    std::vector<double> upper_left(szr.at(0).begin(), szr.at(0).end());
    std::vector<double> upper_right(szr.at(1).begin(), szr.at(1).end());
    double lower_slope = (upper_right.at(1) - upper_left.at(1)) /
                         (upper_right.at(0) - upper_left.at(0));
    double lower_const = upper_right.at(1) - lower_slope * upper_right.at(0);
    std::vector<double> lower_left(szr.at(3).begin(), szr.at(3).end());
    std::vector<double> lower_right(szr.at(2).begin(), szr.at(2).end());
    double upper_slope = (lower_right.at(1) - lower_left.at(1)) /
                         (lower_right.at(0) - lower_left.at(0));
    double upper_const = lower_right.at(1) - upper_slope * lower_right.at(0);

    int frame_res = 4;  // resolution of extrapolating positions between two
                        // relevant pitch frames
    int angle_res = 8;  // angular resolution for generating points on the ball
                        // for boundary check
    double twopi = 4 * std::acos(0.0);
    double th = twopi / static_cast<double>(angle_res);  // angular resolution of the ball for boundary chack
    double radius = avg_relevant_diameter / 2.0;
    pitch_frame_t next_frame;
    double delta_y;
    double delta_x;
    for (int i = 0; i < relevant_frames.size() - 1; i++) {
      curr_frame = this->pitch->get_frame(relevant_frames.at(i));
      next_frame = this->pitch->get_frame(relevant_frames.at(i + 1));
      delta_y = (next_frame.center[1] - curr_frame.center[1]) /
                static_cast<double>(frame_res);
      delta_x = (next_frame.center[0] - curr_frame.center[0]) /
                static_cast<double>(frame_res);
      for (int j = 0; j < frame_res; j++) {
        double x = static_cast<double>(curr_frame.center[0]) + j * delta_x;
        double y = static_cast<double>(curr_frame.center[1]) + j * delta_y;
        for (int k = 0; k < angle_res; k++) {
          double x2 = x + radius * std::cos(k * th);
          double y2 = y + radius * std::sin(k * th);
          if (x2 >= x_min && x2 <= x_max) {
            if ((y2 <= (upper_slope * x2 + upper_const) &&
                 (y2 >= (lower_slope * x2 + lower_const)))) {
              printstr += ": STRIKE!";
              matplotlibcpp::text(10, 25, printstr);
              matplotlibcpp::show();
              return true;
            }
          }
        }
      }
    }
    printstr += ": BALL!";
    matplotlibcpp::text(10, 25, printstr);
    matplotlibcpp::show();
    return false;
  }
}
