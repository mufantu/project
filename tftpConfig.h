#ifndef _TFTPCONFIG_H_
#define _TFTPCONFIG_H_


#include <cstdint>

	class TftpConfig
	{
	private:
		uint32_t _configId;
		uint32_t _minUdpSrcPort;
		uint32_t _maxUdpSrcPort;
		uint32_t _blockSize;
		uint32_t _timeOut;
		uint32_t _retryCount;
		uint32_t _serverPort;
		uint32_t _maxFileSize;
	protected:
	public:
		TftpConfig();
		TftpConfig(uint32_t serverPort, uint32_t minUdpSrcPort, uint32_t maxUdpSrcPort);
		~TftpConfig();

		uint32_t getConfigId()const;
		uint32_t getMinUdpSrcPort()const;
		uint32_t getMaxUdpSrcPort()const;
		uint32_t getBlockSize()const;
		uint32_t getTimeout()const;
		uint32_t getRetryCount()const;
		uint32_t getServerPort()const;
		uint32_t getMaxFileSize()const;


	};




#endif