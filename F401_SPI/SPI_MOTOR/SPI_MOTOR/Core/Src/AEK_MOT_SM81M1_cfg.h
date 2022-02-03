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
 * @file    AEK_MOT_SM81M1_cfg.h
 * @brief   AEK_MOT_SM81M1 Driver configuration macros and structures.
 *
 * @addtogroup AEK_MOT_SM81M1
 * @{
 */

#ifndef _AEK_MOT_SM81M1_CFG_H_
#define _AEK_MOT_SM81M1_CFG_H_

//#include "spc5_lld.h"
//#include "lldconf.h"
//#include "spi_lld.h"
//#include "spi_lld_cfg.h"


#define AEK_MOT_LIST_ELEMENT 2

//extern SPIDriver* AEK_MOT_SM81M1_ARRAY_DRIVER[2];
extern const int AEK_MOT_SM81M1_ARRAY_GPIO_PORT[2];
extern const int AEK_MOT_SM81M1_ARRAY_GPIO_PORT_NUMBER[2];
//extern const SPIConfig* AEK_MOT_SM81M1_ARRAY_CONFIGURATION[2];

typedef enum {
AEK_MOT_SM81M1_DEV0=0
	,	
AEK_MOT_SM81M1_DEV1=1
}AEK_MOT_SM81M1_DEVICE;

extern int position;
extern unsigned char previousMode, rotation;


#endif /* _AEK_MOT_SM81M1_CFG_H_ */

/** @} */
