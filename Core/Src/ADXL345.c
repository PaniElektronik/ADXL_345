/*
 * ADXL345.c
 *
 *  Created on: Jan 27, 2024
 *  Author: AliszjaElectron
 */

#include "ADXL345.h"

bool ADXL345_ReceiveData(uint16_t size, uint8_t data[size], uint8_t addr[size])
{
	bool isReceive = false;
	//TO BE FINISHED

	if (sizeof(&data) ==8 && sizeof(&addr)==8)
	{

	}
	return isReceive;
}

bool ADXL345_SendData(uint16_t size, uint8_t data[size], uint8_t addr[size])
{
	bool isOutOfData = true;
	bool isSend = false;
	uint8_t sendData[16];
	//
	/*
	 * Below is method of connect two array of data:
	 * address register + data to register
	 * That's a frame protocol SPI,
	 * described in datasheet ADXL_345
	 */
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



void ADXL345_Reset()
{

}

