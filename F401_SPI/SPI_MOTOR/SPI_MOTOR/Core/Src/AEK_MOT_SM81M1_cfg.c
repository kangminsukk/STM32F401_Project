/****************************************************************************
*
* Copyright © 2019 STMicroelectronics - All Rights Reserved
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
 * @file    AEK_MOT_SM81M1_cfg.c
 * @brief   AEK_MOT_SM81M1 Driver configuration macros and structures.
 *
 * @addtogroup AEK_MOT_SM81M1
 * @{
 */

#ifndef _AEK_MOT_SM81M1_CFG_C_
#define _AEK_MOT_SM81M1_CFG_C_

//#include "spc5_lld.h"
//#include "lldconf.h"
//#include "spi_lld.h"
//#include "spi_lld_cfg.h"



//
//SPIDriver* AEK_MOT_SM81M1_ARRAY_DRIVER[2]={
//&SPID1
//	,
//&SPID1
//};


const int AEK_MOT_SM81M1_ARRAY_GPIO_PORT[2]={
//PORT_L99SM81V_EN
//	,
//PORT_L99SM81V_EN
};

const int AEK_MOT_SM81M1_ARRAY_GPIO_PORT_NUMBER[2]={
//L99SM81V_EN
//	,
//L99SM81V_EN
};

//const SPIConfig* AEK_MOT_SM81M1_ARRAY_CONFIGURATION[2]={
////&spi_config_SPI_Config
////	,
////&spi_config_SPI_Config
//};

int position =0;
unsigned char previousMode = 0;
unsigned char rotation = 0;


#endif /* _AEK_MOT_SM81M1_CFG_C_ */

/** @} */
