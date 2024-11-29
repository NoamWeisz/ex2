#include <iostream>
#include "profile.h"

//init function set new profile object
void Profile::init(const User owner)
{
	this->owner = new User;
	this->PageOwner = new page;
	this->friendsList = new UserList;
	*this->owner = owner;
	this->friendsList->set_first(nullptr);
	PageOwner->init();
}

//clear object clear the memory of the heap in the object
void Profile::clear()
{
	delete(this->owner);
	delete(this->PageOwner);
	delete(this->friendsList);
}

//getOwner object return a user object that he is the owner of the profile
User Profile::getOwner()const
{
	return *this->owner;
}

//setStatus function set/change status in the profile
void Profile::setStatus(const std::string new_status)
{
	this->PageOwner->setStatus(new_status);
}

//addPostToProfilePage function adds new post to the profile
void Profile::addPostToProfilePage(const std::string post)
{
	this->PageOwner->addLineToPosts(post);
}

//addFriend function add new friend to the profile
void Profile::addFriend(const User friend_to_add)
{
	this->friendsList->add(friend_to_add);

}
//getPage return the page of the profile
std::string Profile::getPage()const
{
	std::string rString = "";
	rString = "Status: ";
	rString += this->PageOwner->getStatus() + "\n";
	rString += "*******************\n";
	rString += "*******************\n";
	rString += this->PageOwner->getPosts();
	return rString;
}




//getFriends function return all the friends of the profile
std::string Profile::getFriends()const
{
	std::string Rstring = "";
	UserNode* curr = NULL;
	if (this->friendsList == nullptr)
	{
		return "";
	}
	curr = friendsList->get_first();

	if (curr == nullptr)
	{
		return "";
	}
	while (curr != nullptr)
	{
		Rstring += curr->get_data().getUserName();
		if (curr->get_next() != nullptr)
		{
			Rstring += ",";
		}
		curr = curr->get_next();
	}
	return Rstring;
}

//getFriendsWithSameNameLength function returns all the
// friends with the same length like the user name length
std::string Profile::getFriendsWithSameNameLength()const
{
	std::string Rstring = "";
	unsigned int len = 0;
	
	if (this->friendsList == nullptr)
	{
		return "";
	}
	UserNode* curr = friendsList->get_first();

	if (curr == nullptr)
	{
		return "";
	}
	len = this->getOwner().getUserName().length();

	while (curr != nullptr)
	{
		if (curr->get_data().getUserName().length() == len)
		{
			Rstring += curr->get_data().getUserName();
			Rstring += ",";
		}
		curr = curr->get_next();
	}
	if (Rstring.length() > 1)
	{
		Rstring.erase(Rstring.size() - 1);
	}
	return Rstring;
}