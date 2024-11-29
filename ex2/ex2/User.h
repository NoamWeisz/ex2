#pragma once
#include <string>
#include "Device.h"
#include "DeviceList.h"

//class user for user object
class User
{
private: //parameters
	unsigned int id;
	std::string username;
	unsigned int age;
	DevicesList *list;
public: //methods
	void init(const unsigned int id,const std::string username,const unsigned int age);
	void clear();
	unsigned int getID()const;
	std::string getUserName()const;
	unsigned int getAge()const;
	DevicesList& getDevices();
	void addDevice(const Device newDevice);
	bool checkIfDevicesAreOn()const;
};