#include "User.h"

#include "iostream"

//init function sets new user object
void User::init(const unsigned int id, const std::string username,const unsigned int age)
{
	this->id = id;
	this->username = username;
	this->age = age;
	this->list = new DevicesList;
	this->list->set_first(nullptr);
}

//checkIfDevicesAreOn function checks if all the devices of the user are active
bool User::checkIfDevicesAreOn()const
{
	DeviceNode* curr = list->get_first();
	if (curr == nullptr)
	{
		return true;
	}
	else
	{
		Device mode = curr->get_data();
		while (curr != nullptr)
		{
			mode = curr->get_data();
			if (!mode.isActive())
			{
				return false;
			}
			curr = curr->get_next();

		}
	}
	return true;
}

//getID function returns the ID of the user;
unsigned int User::getID()const
{
	return id;
}

//getUserName function returns the username of the user
std::string User::getUserName()const
{
	return this->username;
}

//getAge function returns the age of the user
unsigned int User::getAge()const
{
	return this->age;
}

//getDevices funtcion returns a list of all the devices of the user
DevicesList& User::getDevices()
{
	return *list;
}

//addDevice function add new device to the user
void User::addDevice(const Device newDevice)
{
	
	list->add(newDevice);
}

//clear function clears all the memory in the heap that belong to user object
void User::clear()
{
	id = 0;
	username = "";
	age = 0;
	list->clear();
	delete(list);
	list = nullptr;
}
