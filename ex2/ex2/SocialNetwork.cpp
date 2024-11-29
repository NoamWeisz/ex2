#include <iostream>
#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	this->NetName = networkName;
	this->MinAge = minAge;
	this->list = new ProfileList;
	this->list->set_first(nullptr);
}

void SocialNetwork::clear()
{
	this->NetName = "";
	this->MinAge = 0;
	delete(this->list);
	list = NULL;
}

std::string SocialNetwork::getNetworkName()
{
	return this->NetName;
}

int SocialNetwork::getMinAge()
{
	return this->MinAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	User curr = profile_to_add.getOwner();
	bool result = true;
	if (curr.getAge() < this->MinAge)
	{
		return false;
	}
	result = this->list->add(profile_to_add);
	return result;
}
std::string SocialNetwork::getWindowsDevices()
{
	unsigned int ID = 0;
	std::string Rstring = "";
	std::string type = "";
	std::string Windows = "Windows";
	ProfileNode* currProfileList = this->list->get_first();

	while (currProfileList != nullptr)
	{
		Profile currProfile = currProfileList->get_data();
		User currUserlist = currProfile.getOwner();
		DevicesList DeviceList = currUserlist.getDevices();
		DeviceNode* DeviceNode = DeviceList.get_first();
		while (DeviceNode != nullptr)
		{
			Device currData = DeviceNode->get_data();
			type = currData.getOS();
			ID = currData.getID();
			if (type.find(Windows) != std::string::npos)
			{
				Rstring += "[" + std::to_string(ID) + ", " + type + "], ";
			}
			DeviceNode = DeviceNode->get_next();
		}
		currProfileList = currProfileList->get_next();
	}
	if (Rstring.length() > 1)
	{
		Rstring.pop_back();
		Rstring.pop_back();
	}
	return Rstring;
}