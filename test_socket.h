#ifndef _TEST_SOCKET_H_
#define _TEST_SOCKET_H_

#include <cstdint>


	class SocketAddress
	{
	private:
	protected:
	public:
	};




	class MacAddress
	{
	private:
		uint64_t	_macAddress;
	protected:
	public:

		MacAddress();
		MacAddress(uint64_t macAddress) : _macAddress(macAddress)  {         }

		~MacAddress();

		void setMacAddress();
		void setMacAddress(uint64_t macAddress)
		{
			_macAddress = macAddress;
		}
	};





	class Socket
	{
	private:
	protected:
	public:
		virtual ~Socket();
		virtual int32_t  bind()		= 0;
		virtual int32_t  socket()	= 0;
		virtual int32_t	 close()	= 0;

		virtual int32_t  listen()	= 0;

		virtual int32_t  recv()		= 0;
		virtual int32_t  send()		= 0;
	};

	class SocketEthernet : public Socket
	{
	private:
	protected:
	public:

	};

	class SocketAFDX	: public Socket
	{
	private:
	protected:
	public:

	};




#endif // !_TEST_SOCKET_H_
