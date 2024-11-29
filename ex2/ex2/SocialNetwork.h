#pragma once
#include <string>
#include "profile.h"
#include "ProfileList.h"

class SocialNetwork
{
public:
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName();
	int getMinAge();
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices();
private:
	std::string NetName;
	ProfileList* list;
	unsigned int MinAge;
};