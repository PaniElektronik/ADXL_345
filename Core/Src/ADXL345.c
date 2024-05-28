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
bool ADXL345_ReceiveData(uint16_t size, uint8_t data[size], uint8_t addr[size])
{
	bool isReceive = false;


	if (sizeof(&data) ==8 && sizeof(&addr)==8)
	{

	}
	return isReceive;
}
/**
 * ----------------------------------------------------------------
 @brief			Funcion checked result of sended data to ADXL
 	 	 	 	and merged two variables - data and addr - to send a frame
 	 	 	 	according to documentation
 @param[in] 	size - size of frame,
 	 	 	 	data - frame samples,
 	 	 	 	addr - address of data
 @param[out]
 @return		isSend - procedure's flag
 * ----------------------------------------------------------------
 **/
bool ADXL345_SendData(uint16_t size, uint8_t data[size], uint8_t addr[size])
{
	bool isOutOfData = true;
	bool isSend = false;
	uint8_t sendData[16];

	if (size == 8 )
	{
		int j;
		for (j = 0; j < 8; j++)
		{
			sendData[j] = addr[j];
			sendData[j+8] = data[j];
		}
		size = size + j;
		if (size>16)
		{
			isOutOfData = true;
		}
		else
		{
			isOutOfData = false;
		}
	}

	if (isOutOfData == false)
	{
		if(SPI_SendData(size, sendData)==true)
		{
			isSend = true;
		}
	}

	return isSend;
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

