#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <cstdint>
#include <string>



	class IpAddress
	{
	private:
		uint32_t _ipAddress;

		//convert func
	protected:
	public:
		IpAddress();
		IpAddress(const char *ipAddr);
		IpAddress(const std::string ipAddr);
		IpAddress(const uint32_t ipAddr);
		~IpAddress();

		void setIpAddress(const uint32_t ipAddr);
		void setIpAddress(const std::string ipAddr);

		uint32_t	getIntIpAddress();
		std::string getStringIpAddress();

	};





#endif