/****************************************************************************
*
* Copyright � 2019 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0098 at www.st.com.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* EVALUATION ONLY - NOT FOR USE IN PRODUCTION
*****************************************************************************/

/**
 * @file    AEK_MOT_SM81M1_Driver.h
 * @brief   SPC5xx AEK_MOT_SM81M1 header file.
 *
 * @addtogroup AEK_MOT_SM81M1
 * @{
 */
/*******************************************************************************
***************************** New type definition ******************************
*******************************************************************************/
typedef unsigned long int AEK_MOT_SM81M1drv_RegType;

/**
 * @brief Type of a structure representing Step mode.
 */
typedef enum {
	HALF, FULL, MINI, MICRO8, MICRO2, MICRO3, MICRO4
} STEP_MODE;

/**
 * @brief Type of a structure representing Code Error.
 */
typedef enum {
	VSOV, VSUV, VREGOV, VREGUV, CPFAIL, V5UVW, V5VOV, V5VUV, TW, TSD, OL, OC, SDF
} CODE_ERROR;

/**
 * @brief Type of a structure representing Status Stepper Motor.
 */
typedef enum {
	OCA1HS, OCA1LS, OCA2HS, OCA2LS, OCB1HS, OCB1LS, OCB2HS, OCB2LS, OLA, OLB, CVULF, CVLLAF, CVLLBF
} STATUS_MOTOR;

/**
 * @brief Type of a structure representing GCR1 Register.
 */
typedef enum {
	CPWBE, MWBE, AOUT, V5VE, MX1, MX2, MX3
} AEK_MOT_SM81M1_GCR1;

/**
 * @brief Type of a structure representing GCR2 Register.
 */
typedef enum {
	DOUT1, DOUT2
} AEK_MOT_SM81M1_GCR2;

/**
 * @brief Type of a structure representing GCR1 values available.
 */
typedef enum {
	ON, DISABLED, BAND_GAP, VOLTAGE_PROTECTION, OFF, SMODE, HOLD
} OPTION_VALUE_GCR1;

/**
 * @brief Type of a structure representing GCR2 values available.
 */
typedef enum {
	CVRDY, CVLL, CVRUN, PWM, ERR, EC
} OPTION_VALUE_GCR2;

/**
 * @brief Type of a structure representing MCR1.
 */
typedef enum {
	ME, HOLDM, ASM, SM, DIR
}AEK_MOT_SM81M1_MCR1;

/**
 * @brief Type of a structure representing MCR1 values available.
 */
typedef enum {
	MICROSTEP1_16, MICROSTEP1_8, MINISTEP_M, HALFSTEP_M, FULLSTEP_M, DECREMENTAL, PH_PH0, PH_PH1, PH_PH2, PH_PH3, PH_PH4, PH_PH5, ONMCR1
}OPTION_VALUE_MCR1;

/**
 * @brief Type of a structure representing MCR2.
 */
typedef enum {
	FREQ, FTOCE, TBE, FT, SR, DMR, SDAFW, SDBFW, ONDLY, DMH
}AEK_MOT_SM81M1_MCR2;

/**
 * @brief Type of a structure representing MCR1 values available.
 */
typedef enum {
	MIDFREQ, HIGHFREQ, REGULATIONONE, REGULATIONTWO, REGULATIONTHREE, REGULATIONFOUR, AUTO_DECAY_MODE1, AUTO_DECAY_MODE2, SLOW_DECAY, MIX_DECAY, ONMCR2
}OPTION_VALUE_MCR2;

/**
 * @brief Type of a structure representing MCR3.
 */
typedef enum {
	CVE,  AHMSD
}AEK_MOT_SM81M1_MCR3;

/**
 * @brief Type of a structure representing direction of the rotation.
 */
typedef enum {
	LEFT, RIGHT
}TURN_DIRECTION;
/*******************************************************************************
********************************** Functions ***********************************
*******************************************************************************/

#if (AEK_MOT_LIST_ELEMENT != 0)
long decimalToBinary(int n);
void intToArrayMotor(uint32 in, Spi_DataType *out);
void ArrayToIntMotor(Spi_DataType *in, uint32 *out);
boolean checkParityMotor(uint32 in);
uint32 updateParityBitMotor(uint32 in);
void AEK_MOT_SM81M1drv_ReadSPIRegister(SPI_HandleTypeDef* driver,   unsigned char regAddress);
void AEK_MOT_SM81M1drv_WriteSPIRegister(SPI_HandleTypeDef* driver,   unsigned char regAddress, int mode);
void AEK_MOT_SM81M1drv_WriteSPIRegisterMOV(SPI_HandleTypeDef* driver,   unsigned char regAddress, STEP_MODE mode, long int pos, int dir);
void AEK_MOT_SM81M1drv_Read_Device_Info(SPI_HandleTypeDef* driver,   unsigned char regAddress);
void AEK_MOT_SM81M1drv_ClearStausRegister(SPI_HandleTypeDef* driver,   unsigned char regAddress);
uint8 AEK_MOT_SM81M1drv_GetGlobalStatus(void);
void AEK_MOT_SM81M1drv_MotorStatus(SPI_HandleTypeDef* driver,   unsigned char regAddress);
void AEK_MOT_SM81M1drv_ReadMessage(SPI_HandleTypeDef* driver,   unsigned char regAddress);
void AEK_MOT_SM81M1drv_writeMessage(SPI_HandleTypeDef* driver,   unsigned char regAddress, uint24 tmpData_A, uint24* DataReceived);
void AEK_MOT_SM81M1drv_GlobalStatusRegister(SPI_HandleTypeDef* driver,   unsigned char regAddress);
void AEK_MOT_SM81M1drv_GCR1(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, AEK_MOT_SM81M1_GCR1 operation, OPTION_VALUE_GCR1 dinmode);
void AEK_MOT_SM81M1drv_GCR2(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, AEK_MOT_SM81M1_GCR2 operation, OPTION_VALUE_GCR2 dinmode);
void AEK_MOT_SM81M1drv_Rotation(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, int grade);
void AEK_MOT_SM81M1drv_MCR1(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, AEK_MOT_SM81M1_MCR1 operation, OPTION_VALUE_MCR1 dinmode);
void AEK_MOT_SM81M1drv_MCR2(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, AEK_MOT_SM81M1_MCR2 operation, OPTION_VALUE_MCR2 dinmode);
void AEK_MOT_SM81M1drv_MCR3(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, AEK_MOT_SM81M1_MCR3 operation, OPTION_VALUE_MCR1 dinmode);
void AEK_MOT_SM81M1drv_MCV(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, int voltage);
void AEK_MOT_SM81M1drv_VOLTAGE_TIMING(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, int period);
void AEK_MOT_SM81M1drv_STALL_DETECTION(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, int bits);
void AEK_MOT_SM81M1drv_HOLD_MODE(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, int current);
void AEK_MOT_SM81M1drv_FULL_SCALE(SPI_HandleTypeDef* driver,   uint8 regAddress, uint24* DataReceived, int current);
void init_AEK_MOT_SM81M1(SPI_HandleTypeDef* driver);
void TurnLeft(SPI_HandleTypeDef* driver, int step, int time);
void TurnRight(SPI_HandleTypeDef* driver, int step, int time);
void RotationGrade(SPI_HandleTypeDef* driver,int grade, TURN_DIRECTION direction, int time);
void turnCounterclockwise(SPI_HandleTypeDef* driver,int step, STEP_MODE mode);
void turnClockwise(SPI_HandleTypeDef* driver,  int step, STEP_MODE mode);
#endif
 /** @} */


