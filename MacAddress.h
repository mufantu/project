#ifndef _MACADDRESS_H_
#define _MACADDRESS_H_



#include <cstdint>
#include <string>
#include <sstream>




	class MacAddress
	{
	private:
		uint64_t	_macAddress;

		uint64_t	convertStringToInt(std::string str);
		std::string convertIntToString(const uint64_t val);
		void		convertIntToChar(uint8_t *arr, uint64_t val);
		
	protected:
	public:

		MacAddress();
		MacAddress(std::string macAddress);
		MacAddress(uint64_t macAddress);
		~MacAddress();


		void setMacAddress(std::string str);
		void setMacAddress(uint64_t macAddress);

		uint64_t	getIntAddress()const;
		std::string getStringAddress();

		uint32_t getLower()const;
		uint32_t getHiger()const;

	};




#endif