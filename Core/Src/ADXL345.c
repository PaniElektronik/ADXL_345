/**
 * @file 	ADXL345.c
 * @brief 	ADXL345 Accelerometer's Handler
 *
 *
 * @author 	PaniElektronik
 * @date 	21.06.2024
 */

/*------------------------------ INCLUDES ------------------------------*/
#include "ADXL345.h"
/*------------------------------ FUNCTIONS ------------------------------*/
/**
 * @name	ADXL345_WriteRegister
 * @brief	Write data to register
 *
 * @param[in]		uint8_t regAddr,
 * 					uint8_t regData.
 * @param[in,out]	-
 * @param[out]		-
 * @return			isWrite.
 */
bool ADXL345_WriteRegister(uint8_t regAddr, uint8_t regData)
{
	bool isWrite = false;
	uint8_t data[2] = {regAddr, regData};
	if(HAL_I2C_Master_Transmit(&hi2c1, ADXL345_ADDRESS << 1, data, 2, HAL_MAX_DELAY) == HAL_OK)
    {
    	isWrite = true;
    }
    return isWrite;
}
/**
 * @name			ADXL345_ReadRegister
 * @brief			Read data from register
 *
 * @param[in]		uint8_t regAddr.
 * @param[in,out]
 * @param[out]		uint8_t *regData.
 * @return			isSend && isRead
 */
uint8_t ADXL345_ReadRegister(uint8_t regAddr, uint8_t *regData)
{
	bool isSend = false;
	bool isRead = false;

	if(HAL_I2C_Master_Transmit(&hi2c1, ADXL345_ADDRESS << 1, &regAddr, 1, HAL_MAX_DELAY) == HAL_OK)
    {
    	isSend = true;
    	if(HAL_I2C_Master_Receive(&hi2c1, ADXL345_ADDRESS << 1, regData, 1, HAL_MAX_DELAY)==HAL_OK)
    	{
    		isRead = true;
    	}

    }
    if (isRead && isSend == true)
    {
    	return *regData;
    }
    else
    {
    	return regAddr;
    }

}
/**
 * @name			ADXL345_ReadMultiRegister
 * @brief			Read buffer data from register
 *
 * @param[in]		uint8_t regAddr, uint16_t regDataSize
 * @param[in,out]
 * @param[out]		uint8_t *regData.
 * @return			isSend && isRead
 */
bool ADXL345_ReadMultiRegister(uint8_t regAddr, uint8_t *regData, uint16_t regDataSize)
{

	bool isSend = false;
	bool isRead = false;

    if(HAL_I2C_Master_Transmit(&hi2c1, ADXL345_ADDRESS << 1, &regAddr, 1, HAL_MAX_DELAY) == HAL_OK)
    {
    	isSend = true;
    	if(HAL_I2C_Master_Receive(&hi2c1, ADXL345_ADDRESS << 1, regData, regDataSize, HAL_MAX_DELAY)==HAL_OK)
    	{
    		isRead = true;
    	}
    }
    return isRead && isSend;

}
/**
 * @name			ADXL345_Init
 * @brief			ADXL Initialization
 *
 * @param[in]		-
 * @param[in,out]	-
 * @param[out]		-
 * @return			ADXL345_INIT_OK
 */
ADXL345_RegInit ADXL345_Init(void)
{
    if(ADXL345_WriteRegister(ADXL345_REG_POWER_CTL, 0x08) != true)
    {
    	return POWER_CTL_ERR;
    }
	if(ADXL345_WriteRegister(ADXL345_REG_DATA_FORMAT, 0x08) != true)
	{
		return DATA_FORMAT_ERR;
	}
	if(ADXL345_WriteRegister(ADXL345_REG_BW_RATE, 0x0A) != true)
	{
		return BW_RATE_ERR;
	}
	if(ADXL345_WriteRegister(ADXL345_REG_FIFO_CTL, 0x00) != true)
	{
		return FIFO_CTL_ERR;
	}

	return ADXL345_INIT_OK;


}
/**
 * @name
 * @brief
 *
 * @param[in]
 * @param[in,out]
 * @param[out]
 * @return
 */
bool ADXL345_ReadData(int16_t* x, int16_t* y, int16_t* z)
{
    uint8_t rxData[6];
    bool isReadData = false;
    if(ADXL345_ReadMultiRegister(ADXL345_REG_DATAX0, rxData, 6) == true)
    {
    	isReadData = true;
		*x = (int16_t)((rxData[1] << 8) | rxData[0]);
		*y = (int16_t)((rxData[3] << 8) | rxData[2]);
		*z = (int16_t)((rxData[5] << 8) | rxData[4]);
    }
    return isReadData;

}

/**
 * @name
 * @brief
 *
 * @param[in]
 * @param[in,out]
 * @param[out]
 * @return
 */
