#pragma once
#include <string>
#include "profile.h"
#include "ProfileList.h"


//SocialNetwork class for  SocialNetwork object
class SocialNetwork
{
public: //methods
	void init(const std::string networkName,const int minAge);
	void clear();
	std::string getNetworkName()const;
	int getMinAge()const;
	bool addProfile(const Profile profile_to_add);
	std::string getWindowsDevices()const;

private://parameters
	std::string NetName;
	ProfileList* list;
	unsigned int MinAge;
};