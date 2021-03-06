/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define I2C1_SLAVE_ADDRESS	I2C1_Slave_Address
#define BUTTON_PRESS 	1
#define INITALIZE		0
#define WAIT			0
#define READY			1
#define BUTTON_RELEASE  0

#define FND_LEFT_DOT_ON			  HAL_GPIO_WritePin(FND_RIGHT_DOT_PORT_GPIO_Port, FND_RIGHT_DOT_PORT_Pin, GPIO_PIN_RESET); \
  	  	  	  	  	  	  	  	  HAL_GPIO_WritePin(FND_LEFT_DOT_PORT_GPIO_Port, FND_LEFT_DOT_PORT_Pin, GPIO_PIN_SET); \
  	  	  	  	  	  	  	  	  HAL_GPIO_WritePin(GPIOA, FND_DOT_PORT_Pin, GPIO_PIN_RESET);

#define FND_RIGHT_DOT_ON	      HAL_GPIO_WritePin(FND_RIGHT_DOT_PORT_GPIO_Port, FND_RIGHT_DOT_PORT_Pin, GPIO_PIN_SET); \
  	  	  	  	  	  	  	  	  HAL_GPIO_WritePin(FND_LEFT_DOT_PORT_GPIO_Port, FND_LEFT_DOT_PORT_Pin, GPIO_PIN_RESET); \
  	  	  	  	  	  	  	  	  HAL_GPIO_WritePin(GPIOA, FND_DOT_PORT_Pin, GPIO_PIN_RESET);

#define	FND_COM_LEFT_ON  	      HAL_GPIO_WritePin(GPIOC, FND_LEFT_PORT_Pin, GPIO_PIN_SET); \
								  HAL_GPIO_WritePin(GPIOC, FND_RIGHT_PORT_Pin, GPIO_PIN_RESET); \

#define	FND_COM_RIGHT_ON	      HAL_GPIO_WritePin(GPIOC, FND_RIGHT_PORT_Pin, GPIO_PIN_SET); \
								  HAL_GPIO_WritePin(GPIOC, FND_LEFT_PORT_Pin, GPIO_PIN_RESET); \

#define FND_SEG_NUM0_DISP	      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_G_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM1_DISP	      HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin|FND_C_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOA, FND_A_PORT_Pin, GPIO_PIN_SET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM2_DISP	      HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin, GPIO_PIN_SET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM3_DISP	      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM4_DISP	      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOA, FND_A_PORT_Pin, GPIO_PIN_SET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin|FND_D_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM5_DISP      	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin, GPIO_PIN_SET); \
                                  HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM6_DISP	      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM7_DISP	      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET); \

#define FND_SEG_NUM8_DISP	      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						          HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET);

#define FND_SEG_NUM9_DISP	      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_G_PORT_Pin|FND_D_PORT_Pin, GPIO_PIN_RESET); \
                                  HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin, GPIO_PIN_SET);
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 uint8_t I2C1_Slave_Address = 0x44 << 1;
 uint8_t I2C1_TX[2] = {0x2C, 0x06};
 uint8_t I2C1_RX[6] = {0,};
 uint16_t I2C1_Temp = 0;
 uint16_t I2C1_Humi = 0;
 uint8_t Button_Count = 0;
 uint8_t RH = 0;
 uint8_t Degree_Celsius = 0;
 uint8_t User_Button_Status = 0;
 uint8_t disp10 = 0;
 uint8_t disp1 = 0;
 uint8_t I2C1_Calc = 0;
 uint8_t I2C1_Communication = 0;
 uint8_t I2C1_Data = 1;
 uint8_t FND_vector = 0;
 uint8_t User_Button_Value = 0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void NUM_SEG_DISPLAY(uint8_t Disp_Seg_Num)
{
	switch(Disp_Seg_Num)
	{
	case 0:
		FND_SEG_NUM0_DISP
		break;
	case 1:
		FND_SEG_NUM1_DISP
		break;
	case 2:
		FND_SEG_NUM2_DISP
		break;
	case 3:
		FND_SEG_NUM3_DISP
		break;
	case 4:
		FND_SEG_NUM4_DISP
		break;
	case 5:
		FND_SEG_NUM5_DISP
		break;
	case 6:
		FND_SEG_NUM6_DISP
		break;
	case 7:
		FND_SEG_NUM7_DISP
		break;
	case 8:
		FND_SEG_NUM8_DISP
		break;
	case 9:
		FND_SEG_NUM9_DISP
		break;
	default:
		FND_SEG_NUM0_DISP
		break;
	}
}
void I2C1_FND_Calc(uint8_t I2C1_data)
{
	disp10 = I2C1_data / 10;
	disp1 = I2C1_data % 10;
}

void I2C1_Data_Calc()
{
	if(I2C1_Calc == 0)
	{
		Degree_Celsius = (-45 + (175*(I2C1_Temp / 65535.0)));
		I2C1_FND_Calc(Degree_Celsius);
		FND_LEFT_DOT_ON
		I2C1_Calc = 1;
	}

	else if(I2C1_Calc == 1)
	{
		RH = (100 * (I2C1_Humi / 65535.0));
		I2C1_FND_Calc(RH);
		FND_RIGHT_DOT_ON
		I2C1_Data = 1;
		I2C1_Calc = 0;
	}
}

void I2C1_Master_Data()
{
	if(HAL_I2C_Master_Receive(&hi2c1, I2C1_SLAVE_ADDRESS, I2C1_RX, 6, 10000) == HAL_OK)
	{
		I2C1_Temp = ((I2C1_RX[0] << 8) + I2C1_RX[1]);
		I2C1_Humi = ((I2C1_RX[3] << 8) + I2C1_RX[4]);
	}

	else
	{
		I2C1_Temp = 0;
		I2C1_Humi = 0;
	}
}

void I2C1_Communication_Ctrl()
{
	if(I2C1_Communication == READY && I2C1_Data == READY)
	{
		if(HAL_I2C_Master_Transmit(&hi2c1, I2C1_SLAVE_ADDRESS, I2C1_TX, 2, 10000) == HAL_OK)
		{
			I2C1_Master_Data();
		}

		else
		{
			I2C1_Temp = 0;
			I2C1_Humi = 0;
		}
	}
	I2C1_Communication = WAIT;
	I2C1_Data = WAIT;

	I2C1_Data_Calc();
}

int User_Button_Press_Release_Ctrl(uint8_t User_Button_Ctrl)
{
   if((HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin)==0)&&(User_Button_Status == 0))
   {
	   Button_Count++;
	   if(Button_Count > 0)
	   {
		   User_Button_Status = 1;
		   I2C1_Communication = READY;
		   User_Button_Ctrl = BUTTON_PRESS;
	   }
   }

   else if(HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin)==1)
   {
	   Button_Count = INITALIZE;
	   User_Button_Status = 0;
	   User_Button_Ctrl = BUTTON_RELEASE;
   }

   return User_Button_Ctrl;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

	HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim3);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  User_Button_Value = User_Button_Press_Release_Ctrl(INITALIZE);

	  if(User_Button_Value == BUTTON_PRESS)
	  {
		  I2C1_Communication_Ctrl();
	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 136;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 840-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 100-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, FND_RIGHT_PORT_Pin|FND_LEFT_PORT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin|FND_DOT_PORT_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(FND_RIGHT_DOT_PORT_GPIO_Port, FND_RIGHT_DOT_PORT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(FND_LEFT_DOT_PORT_GPIO_Port, FND_LEFT_DOT_PORT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : USER_BUTTON_Pin */
  GPIO_InitStruct.Pin = USER_BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_BUTTON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : FND_RIGHT_PORT_Pin FND_LEFT_PORT_Pin */
  GPIO_InitStruct.Pin = FND_RIGHT_PORT_Pin|FND_LEFT_PORT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : FND_C_PORT_Pin FND_B_PORT_Pin FND_RIGHT_DOT_PORT_Pin FND_A_PORT_Pin
                           FND_DOT_PORT_Pin */
  GPIO_InitStruct.Pin = FND_C_PORT_Pin|FND_B_PORT_Pin|FND_RIGHT_DOT_PORT_Pin|FND_A_PORT_Pin
                          |FND_DOT_PORT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : FND_LEFT_DOT_PORT_Pin FND_F_PORT_Pin FND_D_PORT_Pin FND_G_PORT_Pin
                           FND_E_PORT_Pin */
  GPIO_InitStruct.Pin = FND_LEFT_DOT_PORT_Pin|FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin
                          |FND_E_PORT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(FND_vector == 0)
	{
		FND_COM_LEFT_ON
		NUM_SEG_DISPLAY(disp10);
		FND_vector = 1;
	}

	else if(FND_vector == 1)
	{
		FND_COM_RIGHT_ON
		NUM_SEG_DISPLAY(disp1);
		FND_vector = 0;
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
