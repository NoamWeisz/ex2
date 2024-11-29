#include <iostream>
#include "profile.h"

void Profile::init(User owner)
{
	this->owner = new User;
	this->PageOwner = new page;
	this->friendsList = new UserList;
	*this->owner = owner;
	this->friendsList->set_first(nullptr);
	PageOwner->init();
}

void Profile::clear()const
{
	delete(this->owner);
	delete(this->PageOwner);
	delete(this->friendsList);
}


User Profile::getOwner()const
{
	return *this->owner;
}

void Profile::setStatus(std::string new_status)
{
	this->PageOwner->setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	this->PageOwner->addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	this->friendsList->add(friend_to_add);

}

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





std::string Profile::getFriends()
{
	std::string Rstring = "";
	if (this->friendsList == nullptr)
	{
		return "";
	}
	UserNode* curr = friendsList->get_first();

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

std::string Profile::getFriendsWithSameNameLength()
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