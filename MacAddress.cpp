#include "MacAddress.h"



MacAddress::MacAddress() : _macAddress(0)
{
	
}

MacAddress::MacAddress(uint64_t macAddress) : _macAddress(macAddress)
{

}

MacAddress::MacAddress(std::string macAddress)
{
	_macAddress = convertStringToInt(macAddress);
}

MacAddress::~MacAddress()
{

}



void MacAddress::setMacAddress(std::string str)
{
	_macAddress = convertStringToInt(str);
}


void MacAddress::setMacAddress(uint64_t macAddress)
{
	_macAddress = macAddress;
}




uint64_t MacAddress::getIntAddress()const
{
	return _macAddress;
}

std::string MacAddress::getStringAddress()
{
	return convertIntToString(_macAddress);
}


uint64_t MacAddress::convertStringToInt(std::string str)
{
	std::istringstream iss(str);
	uint64_t nibble;
	uint64_t result(0);
	iss >> std::hex;
	while (iss >> nibble) {
		result = (result << 8) + nibble;
		iss.get();
	}
	return result;
}


std::string MacAddress::convertIntToString(const uint64_t val)
{
	const uint32_t SIZE_BUF = 8;
	uint8_t macAddr[SIZE_BUF];
	convertIntToChar(macAddr, val);

	std::stringstream ss;

	for (uint32_t i = 2; i < SIZE_BUF; i++)
	{
		if ((uint64_t)macAddr[i] == 0 || (uint64_t)macAddr[i] < 10)
		{
			if ((uint64_t)macAddr[i] < 10)
			{
				ss << "0";
				ss << std::hex << (uint64_t)macAddr[i];
				if (i < SIZE_BUF - 1)
					ss << ":";
			}
			else
			{
				ss << std::hex << (uint64_t)macAddr[i];
				ss << "0:";
				
			}	
		}
		else
		{
			ss << std::hex << (uint64_t)macAddr[i];
			if (i < SIZE_BUF - 1)
				ss << ":";
		}
	}
	std::string str(ss.str());
	return str;
}

void MacAddress::convertIntToChar(uint8_t *arr, uint64_t val)
{
	arr[0] = (uint64_t)((val & 0xff00000000000000) >> 56);
	arr[1] = (uint64_t)((val & 0x00ff000000000000) >> 48);
	arr[2] = (uint64_t)((val & 0x0000ff0000000000) >> 40);
	arr[3] = (uint64_t)((val & 0x000000ff00000000) >> 32);
	arr[4] = (uint64_t)((val & 0x00000000ff000000) >> 24);
	arr[5] = (uint64_t)((val & 0x0000000000ff0000) >> 16);
	arr[6] = (uint64_t)((val & 0x000000000000ff00) >> 8);
	arr[7] = (uint64_t)((val & 0x00000000000000ff));
}