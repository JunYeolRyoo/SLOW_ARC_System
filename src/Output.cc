#include "../include/Output.h"

Output::Output(){
    this->curr_call = BallStrikeClassifier();
}

bool Output::report_verdict(std::string s){
    return curr_call.classify_ball_strike(s);
}
