#include <iostream>
#include <string.h>
#include "Device.h"




void Device::activate()
{
	mood = true;
}

void Device::deactivate()
{
	mood = false;
}

bool Device::isActive()const
{
	return mood;
}

std::string Device::getOS()const
{
	return OStype;
}

DeviceType Device::getType()const
{
	return type;
}
unsigned int Device::getID()const
{
	return id;
}
void Device::init(unsigned int Phoneid, DeviceType Phonetype,
	std::string Phoneos)
{
	id = Phoneid;
	type = Phonetype;
	OStype = Phoneos;
}