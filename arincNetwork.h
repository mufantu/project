#ifndef _ARINCNETWORK_H_
#define _ARINCNETWORK_H_


	typedef enum 
	{
		AFDX_100MBit,
		AFDX_10MBit,
		AFDX_AUTO_100MBit,
		AFDX_AUTO_10MBit,
	}afdxNetworkSpeed;

	typedef enum
	{
		AFDX_NETWORK_A,
		AFDX_NETWORK_B,
		AFDX_BOTH
	}afdxNetwork;

	typedef enum
	{
		AFDX_SINGLE,
		AFDX_REDUNDANT
	}afdxNetworkMode;

	typedef enum
	{
		AFDX_NO_LINK,
		AFDX_GOOD_LINK
	}afdxNetworkLink;


#endif