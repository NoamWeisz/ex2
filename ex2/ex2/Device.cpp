#include <iostream>
#include <string.h>
#include "Device.h"



//device function set device to active mode
void Device::activate()
{
	mood = true;
}

//deactivate function set device to inactive mode
void Device::deactivate()
{
	mood = false;
}

//isActive function check if the device active or not
bool Device::isActive()const
{
	return mood;
}

//getOS function return the OS type of the device
std::string Device::getOS()const
{
	return OStype;
}

//getType function return the type of the device
DeviceType Device::getType()const
{
	return type;
}

//getID function return the ID of the device
unsigned int Device::getID()const
{
	return id;
}

//init function set new device

void Device::init(const unsigned int Phoneid, const DeviceType Phonetype,
	const std::string Phoneos)
{
	this->id = Phoneid;
	this->type = Phonetype;
	this->OStype = Phoneos;
}