#include <iostream>
#include "Page.h"

//init fucntion set new page object
void page::init()
{
	this->posts = "";
	this->status = "";

}

//getPosts function return all the post in the page
std::string page::getPosts()const
{
	return this->posts;
}

//getStatus function return the status of the page
std::string page::getStatus()const
{
	return this->status;
}

//clearPage function clear the posts in the page
void page::clearPage()
{
	this->posts = "";
}

//setStatus function change/set the status in the page
void page::setStatus(const std::string status)
{
	this->status = status;
}

//addLineToPosts function add new post to the page
void page::addLineToPosts(const std::string new_line)
{
	this->posts += new_line;
	this->posts += "\n";
}

