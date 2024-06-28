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
 * @name			ADXL345_WriteRegister
 * @brief			Write data to register
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
 * @param[out]		ADXL345_RegInit,
 * @return			ADXL345_INIT_OK
 */
ADXL345_RegInit ADXL345_Init(void)
{
	if (!ADXL345_WriteRegister(ADXL345_REG_POWER_CTL, 0x08))  // Włączenie czujnika
	    {
	        return POWER_CTL_ERR;
	    }
	    if (!ADXL345_WriteRegister(ADXL345_REG_DATA_FORMAT, 0x08))  // Ustawienie zakresu ±2g
	    {
	        return DATA_FORMAT_ERR;
	    }
	    if (!ADXL345_WriteRegister(ADXL345_REG_BW_RATE, 0x0A))  // Ustawienie częstotliwości próbkowania
	    {
	        return BW_RATE_ERR;
	    }
	    if (!ADXL345_WriteRegister(ADXL345_REG_FIFO_CTL, 0x00))  // Ustawienie FIFO w trybie bypass
	    {
	        return FIFO_CTL_ERR;
	    }
	    if (!ADXL345_WriteRegister(ADXL345_REG_TAP_AXES, 0x07))  // Ustawienie detekcji tapnięć na wszystkich osiach
	    {
	        return TAP_AXES_ERR;
	    }
	    if (!ADXL345_WriteRegister(ADXL345_REG_THRESH_TAP, 0x20))  // Ustawienie progu tapnięcia
	    {
	        return THRESH_TAP_ERR;
	    }
	    if (!ADXL345_WriteRegister(ADXL345_REG_DUR, 0x10))  // Ustawienie czasu trwania tapnięcia
	    {
	        return DUR_ERR;
	    }
	    if (!ADXL345_WriteRegister(ADXL345_REG_LATENT, 0x10))  // Ustawienie czasu latencji między tapnięciami
	    {
	        return LATENT_ERR;
	    }
	    if (!ADXL345_WriteRegister(ADXL345_REG_WINDOW, 0x30))  // Ustawienie okna czasowego na detekcję podwójnego tapnięcia
	    {
	        return WINDOW_ERR;
	    }

	  return ADXL345_INIT_OK;


}
/**
 * @name			ADXL345_ReadData
 * @brief			Read data from ADXL and converted data
 *
 * @param[in]		-
 * @param[in,out]	int16_t* x,
 * 					int16_t* y,
 * 					int16_t* z
 * @param[out]		-
 * @return			bool isReadData
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
 * @name			ConvertToMS2
 * @brief			Convert variable to m/s^2
 *
 * @param[in]		int16_t raw,
 * 					SCALE_FACTOR,
 * 					GRAVITY
 * @param[in,out]	-
 * @param[out]		float* ms2
 * @return
 */


void ConvertToMS2(int16_t raw, float* ms2)
{
    *ms2 = raw * SCALE_FACTOR * GRAVITY;
}

/**
 * @name			CalculateDisplacement
 * @brief			Calculate m/s^2 to meters
 *
 * @param[in]		-
 * @param[in,out]	-
 * @param[out]		-
 * @return			bool isCalculate,
 */


bool CalculateDisplacement(void)
{
    bool isCalculate = false;
    int16_t x_raw, y_raw, z_raw;
    float ax, ay, az;
    static float vx = 0, vy = 0, vz = 0;
    static float dx = 0, dy = 0, dz = 0;
    float dt = SAMPLE_PERIOD;

    if (ADXL345_ReadData(&x_raw, &y_raw, &z_raw) == true)
    {
        ConvertToMS2(x_raw, &ax);
        ConvertToMS2(y_raw, &ay);
        ConvertToMS2(z_raw, &az);


        vx += ax * dt;
        vy += ay * dt;
        vz += az * dt;


        dx += vx * dt;
        dy += vy * dt;
        dz += vz * dt;


        isCalculate = true;
    }

    return isCalculate;
}


