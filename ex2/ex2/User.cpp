#include "User.h"

#include "iostream"


void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->id = id;
	this->username = username;
	this->age = age;
	this->list = new DevicesList;
	this->list->set_first(nullptr);
}

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

unsigned int User::getID()const
{
	return id;
}

std::string User::getUserName()const
{
	return this->username;
}

unsigned int User::getAge()const
{
	return this->age;
}

DevicesList& User::getDevices()
{
	return *list;
}

void User::addDevice(Device newDevice)
{
	
	list->add(newDevice);
}

void User::clear()
{
	id = 0;
	username = "";
	age = 0;
	list->clear();
	delete(list);
	list = nullptr;
}
