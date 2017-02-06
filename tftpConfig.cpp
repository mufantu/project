#include "tftpConfig.h"



TftpConfig::TftpConfig() :	_blockSize(0), 
							_timeOut(1), 
							_retryCount(1), 
							_serverPort(59),
							_maxFileSize(0)
{

}



uint32_t TftpConfig::getMinUdpSrcPort()const
{
	return _minUdpSrcPort;
}


uint32_t TftpConfig::getMaxUdpSrcPort()const
{
	return _maxUdpSrcPort;
}

uint32_t TftpConfig::getBlockSize()const
{
	return _blockSize;
}

uint32_t TftpConfig::getTimeout()const
{
	return _timeOut;
}

uint32_t TftpConfig::getRetryCount()const
{
	return _retryCount;
}

uint32_t TftpConfig::getConfigId()const
{
	return _configId;
}

uint32_t TftpConfig::getServerPort()const
{
	return _serverPort;
}

uint32_t TftpConfig::getMaxFileSize()const
{
	return _maxFileSize;
}