#pragma once



#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType { PHONE, PC, LAPTOP, TABLET };		     //
//
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
														 //
/// ///////////////////////////////////////////////////////

/*
device class for device object
*/
class Device
{
private: //parameters
	std::string OStype;
	bool mood;
	unsigned int id;
	DeviceType type;

public:
	void activate(); //methods
	void deactivate();
	void init(const unsigned int Phoneid,const DeviceType Phonetype,const std::string Phoneos);
	std::string getOS()const;
	bool isActive()const;
	unsigned int getID()const;
	DeviceType getType()const;
};









