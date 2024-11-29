#pragma once
#include <string>

class page
{
private:
	std::string status;
	std::string posts;
public:
	void init();
	std::string getPosts()const;
	std::string getStatus()const;
	void setStatus(const std::string status);
	void addLineToPosts(std::string new_line);
	void clearPage();
};
