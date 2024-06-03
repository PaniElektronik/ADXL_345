/**
 * ----------------------------------------------------------------
 @file		ADXL345.c
 @anchor
 @brief		ADXL345 Accelerometer Implementation
 @author	Alicja Gackowiec (PaniElektronik)
 @version	v1.0
 * ----------------------------------------------------------------
 **/

#include "ADXL345.h"

/**
 * ----------------------------------------------------------------
 @brief			Funcion checked result of received data from ADXL
 @param[in]		size - size of frame,
 	 	 	 	data - frame samples,
 	 	 	 	addr - address of data
 @param[out]
 @return		isReceive - procedure's flag
 * ----------------------------------------------------------------
 **/
bool ADXL345_ReadReg(uint8_t data, uint8_t addr)
{
	bool isReceive = false;
	bool isSend = false;

		if(SPI_SendData(addr) == true)
		{
			if(SPI_ReceiveData(data) == true)
			{
				isReceive = true;
			}
			isSend = true;
		}

	return isReceive & isSend;
}
/**
 * ----------------------------------------------------------------
 @brief			Funcion checked result of sended data to ADXL
 	 	 	 	and merged two variables - data and addr - to send a frame
 	 	 	 	according to documentation of ADXL
 @param[in] 	size - size of frame,
 	 	 	 	data - frame samples,
 	 	 	 	addr - address of data
 @param[out]
 @return		isSend - procedure's flag
 * ----------------------------------------------------------------
 **/
bool ADXL345_WriteReg(uint8_t data, uint8_t addr)
{

	bool isSend = false;
	uint16_t sendData = (addr << 4) + data;

		if(SPI_SendData(sendData)==true)
		{
			isSend = true;
		}
	return isSend;
}

/**
 * ----------------------------------------------------------------
 @brief			Funcion initialization accelerometer to proper
 	 	 	 	first operations
 @param[in]		-
 @param[out]	-
 @return		-
 * ----------------------------------------------------------------
 **/
void ADXL345_Init()
{
	// value of proper DEVID is 0xE5 (345 octal)

	uint8_t addr = DEVID_R;
	uint8_t data = 0xE5;

	//bool isDeviceID = false;
	ADXL345_ReadReg(data,addr);
	if (data == 0xE5)
	{

	}

}

/**
 * ----------------------------------------------------------------
 @brief			Function reset a Accelerometer ADXL345
 @param[in]		-
 @param[out]	-
 @return		pocedure's flag
 * ----------------------------------------------------------------
 **/
void ADXL345_Reset()
{

}

