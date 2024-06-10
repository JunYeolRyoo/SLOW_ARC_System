#include <iostream>
#include <filesystem>
#include <string>
#include <sys/stat.h>
#include "include/PitchTracker.h"
#include "include/PitchRepresentation.h"
#include "include/HomePlateRepresentation.h"
#include "include/HomePlateTracker.h"
#include "include/BatterRepresentation.h"
#include "include/BatterTracker.h"
#include "include/Feed.h"
#include "include/BallStrikeClassifier.h"
#include "include/StrikeZoneDeterminer.h"
#include "include/StrikeZoneRepresentation.h"
#include "include/Output.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
      std::cout << "Invalid usage. Expected ./main <image_data_directory>" << std::endl;
      return 1;
    }
	
    std::string dir_path = argv[1];
    if ((!std::filesystem::exists(dir_path)) | (!std::filesystem::is_directory(dir_path))) {
        std::cout << "The given directory does not exist" << std::endl;
	return 1;
    }
    Feed* feed = Feed::getInstance();
    feed->set_feed_dir(dir_path);
    Output out;
    // Iterate over the directory for pitch data
    for (const auto& entry : std::filesystem::directory_iterator(dir_path)) {
	std::string filename = entry.path().filename();
        std::string curr_feed = entry.path().string();
        feed->set_curr_feed(curr_feed);
        out = Output();
	bool verdict = out.report_verdict(filename);
	if (verdict) {
            std::cout << "Verdict for pitch in " << filename << ": STRIKE!" << std::endl;
	} else {
            std::cout << "Verdict for pitch in " << filename << ": BALL!" << std::endl;
	}
    } 

    return 0;
}
