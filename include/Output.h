#ifndef OUT_H_
#define OUT_H_
#include "BallStrikeClassifier.h"

/*
Description: The primary function of this class is to return to return the determination of wether or not the pitch was a ball or a stike.
*/
class Output {
    private:
        /*
        Description: This private feild is used to determine wether or not a pitch is a ball or a strike based on the data in the input feed.
        Type: BallStrikeClassifier
        */
        BallStrikeClassifier curr_call;
        
    public:
        /*
        Description: Default constructor
        Parameters: None
        */
        Output();
        
    
        /*
        Description: This method reports the verdict of if a pitch was a ball or a strike based on the internal logic of BallStrikeClassifier class to ExternalUI.
        Parameters: None
        Retern: Returns a boolean representation on if the pitch was a ball or a strike.
        */
        bool report_verdict(std::string s);
};

#endif
