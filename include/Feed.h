#ifndef FEED_H_
#define FEED_H_

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

/*
Description: The primary function of this class is to store and return the path to the current data to be processed for all other classes that require access to it.
*/
class Feed {
	private:
	/*
	Description: This private field is used to store the path to the input directory.
	Type: string
	*/
	std::string feed_dir;
	
	/*
	Desctription: This private field stores the name of the current file to be processed in the input directory.
	Type: string
	*/
	std::string curr_feed;
	
	/*
	Description: The static instance of the Feed object.
	Type: Feed
	*/
	static Feed* instancePtr;


	/*
	Description: Default constructor
	Parameters: None
	*/
	Feed();
	
	
	public:
	/*
	Description: Deletes copy constructor.
	*/
	Feed(const Feed& obj) = delete;


	/*
	Description: This Method is used to get instance of feed. Instead of calling a constructor from other classes, call 
		- Feed::getInstance() 
	Parameters: None.
	Returns: Returns a pointer to the singleton.
	*/
	static Feed* getInstance();


	/*
	Description: This Method is used to get the current feed from the input directory.
	Parameters: None.
	Returns: A string containing the path to the current feed.
	*/
	std::string get_curr_feed();


	/*
	Description: This Method is used to set the current feed in the Feed object to the next feed needed from the input directory.
	Parameters: 
		- new_feed: A string containing the path to the new current feed.
	Returns: Void
	*/
	void set_curr_feed(std::string new_feed);


	/*
	Description: This Method is used to get the path to the current feed in the input directory.
	Parameters: None.
	Returns: A string containing the path to the current input directory.
	*/
	std::string get_feed_dir();


	/*
	Description: This Method is used to set the path to the input directory current in the Feed singleton.
	Parameters: 
		- new_dir: A string containing the path to the input directory.
	Returns: Void
	*/
	void set_feed_dir(std::string new_dir);


};

#endif
