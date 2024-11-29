#pragma once
#include <string>
#include "User.h"
#include "page.h"
#include "UserList.h"
#include "Device.h"
#include "DeviceList.h"


//class profile for profile object 

class Profile
{
private: //parameters
	User* owner;
	page* PageOwner;
	UserList* friendsList;

public: //methods
	void init(const User owner);
	void clear();
	User getOwner()const;
	void setStatus(const std::string new_status);
	void addPostToProfilePage(const std::string post);
	void addFriend(const User friend_to_add);
	std::string getPage()const;
	std::string getFriends()const;
	std::string getFriendsWithSameNameLength()const;
};