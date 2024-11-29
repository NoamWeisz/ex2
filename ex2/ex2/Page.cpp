#include <iostream>
#include "Page.h"


void page::init()
{
	this->posts = "";
	this->status = "";

}
std::string page::getPosts()const
{
	return this->posts;
}

std::string page::getStatus()const
{
	return this->status;
}
void page::clearPage()
{
	this->posts = "";
}

void page::setStatus(const std::string status)
{
	this->status = status;
}

void page::addLineToPosts(std::string new_line)
{
	this->posts += new_line;
	this->posts += "\n";
}

