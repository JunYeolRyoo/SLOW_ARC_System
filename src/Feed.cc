#include "../include/Feed.h"

Feed* Feed::instancePtr = NULL;

Feed::Feed(){}

Feed* Feed::getInstance(){
    if (instancePtr == NULL) {
        instancePtr = new Feed();
	return instancePtr;
    }
    else {
        return instancePtr;
    }
}

std::string Feed::get_curr_feed() {
    return this->curr_feed;
}

void Feed::set_curr_feed(std::string new_feed) {
    this->curr_feed = new_feed;
}

std::string Feed::get_feed_dir() {
    return this->feed_dir;
}

void Feed::set_feed_dir(std::string new_dir) {
    this->feed_dir = new_dir;
}
