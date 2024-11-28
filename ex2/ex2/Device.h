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


class Device
{
public:
	std::string OStype = "";
	bool mood = true;
	unsigned int id = 0;
	DeviceType type = PHONE;

	void activate();
	void deactivate();
	void init(unsigned int Phoneid, DeviceType Phonetype,
		std::string Phoneos);

	std::string getOS()const;
	bool isActive()const;
	unsigned int getID()const;
	DeviceType getType()const;
};









