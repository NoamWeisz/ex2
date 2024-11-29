#pragma once
#include <string>


//page class for page object
class page
{
private: //parameters
	std::string status;
	std::string posts;
public:
	void init(); //methods
	std::string getPosts()const;
	std::string getStatus()const;
	void setStatus(const std::string status);
	void addLineToPosts(const std::string new_line);
	void clearPage();
};
