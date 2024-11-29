#include <iostream>
#include "SocialNetwork.h"

//init function set new SocialNetwork object
void SocialNetwork::init(const std::string networkName,const int minAge)
{
	this->NetName = networkName;
	this->MinAge = minAge;
	this->list = new ProfileList;
	this->list->set_first(nullptr);
}

//clear function clear the object and all the memory in the heap
void SocialNetwork::clear()
{
	this->NetName = "";
	this->MinAge = 0;
	delete(this->list);
	list = NULL;
}

//getNetworkName function returns the name of the Social Network
std::string SocialNetwork::getNetworkName()const
{
	return this->NetName;
}

//getMinAge function returns the minimum age of the Social Network
int SocialNetwork::getMinAge()const
{
	return this->MinAge;
}

//addProfile function returns true or false if adding new friends is succsed 
bool SocialNetwork::addProfile(const Profile profile_to_add)
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

//getWindowsDevices function returns string with all the devices of the user that used windows as OS
std::string SocialNetwork::getWindowsDevices()const
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