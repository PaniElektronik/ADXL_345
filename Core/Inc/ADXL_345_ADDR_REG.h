/*
 * ADXL_345_ADDR_REG.h
 *
 *  Created on: Mar 5, 2024
 *      Author: algac
 */

#ifndef SRC_ADXL_345_ADDR_REG_H_
#define SRC_ADXL_345_ADDR_REG_H_
#endif /* SRC_ADXL_345_ADDR_REG_H_ */


#define		DEVID_R				0x00	//Device ID
#define		THRESH_TAP_RW		0x1D	//Tap treshold
#define 	DUR_RW				0x21	//Tap duration
#define 	LATENT_RW			0x22	//Tap latency
#define		WINDOW_RW			0x23	//Tap window

#define		OFSX_RW				0x1E	//X-axis offset
#define		OFSY_RW				0x1F	//Y-axis offset
#define		OFSZ_RW				0x20	//Z-axis offset

#define		THRESH_ACT_RW		0x24	//Activity threshold
#define		THRESH_INACT_RW		0x25	//Inactive treshold

#define 	TIME_INACT_RW		0x26	//Inactive time
#define 	ACT_INACT_CTL_RW	0x27	//Axis enable control for activity and inactivity detection

#define		THRESH_FF_RW		0x28	//Free-fall detection
#define 	TIME_FF_RW			0x29	//Free-fall time
#define 	TAP_AXES_RW			0x2A	//Axis control for single tap/double tap
#define 	ACT_TAP_STATUS_R	0x2B	//Source of single tap/double tap
#define		BW_RATE_RW			0x2C	//Data rate and power mode control
#define		POWER_CTRL_RW		0x2D	//Power-saving features control

#define		INT_ENABLE_RW		0x2E	//Interrupt enable control
#define		INT_MAP_RW			0x2F	//Interrupt mapping control
#define		INT_SOURCE_R		0x30	//Source of interrupts

#define		DATA_FORMAT_RW		0x31	//Data format control
#define		DATAX0_R			0x32	//X-axis data
#define		DATAX1_R			0x33
#define		DATAY0_R			0x34	//Y-axis data
#define		DATAY1_R			0x35
#define 	DATAZ0_R			0x36	//Z-axis data
#define 	DATAZ1_R			0x37

#define		FIFO_CTL_RW			0x38	//FIFO control
#define		FIFO_STATUS_R		0x39	//FIFO status
