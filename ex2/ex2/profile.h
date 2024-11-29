#pragma once
#include <string>
#include "User.h"
#include "page.h"
#include "UserList.h"
#include "Device.h"
#include "DeviceList.h"


class Profile
{
private:
	User* owner;
	page* PageOwner;
	UserList* friendsList;

public:
	void init(User owner);
	void clear()const;
	User getOwner()const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage()const;
	std::string getFriends();
	std::string getFriendsWithSameNameLength();
};