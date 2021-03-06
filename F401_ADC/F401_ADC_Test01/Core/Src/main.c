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
#define FND_LEFT_ON	1
#define FND_RIGHT_ON	2
#define MIN_BUTTON_COUNT	0
#define BUTTON_COUNT_INITIALIZE	0
#define FND_INITIALIZE	0
#define RELEASED_BUTTON	0
#define PRESSED_BUTTON	1
#define PRESS_USER_BUTTON	0
#define RELEASE_USER_BUTTON	1
#define INTERRUPT_OCCURRED	1
#define INTERRUPT_WAITING	0
#define	FND_COM_LEFT_CLEAR		HAL_GPIO_WritePin(GPIOC, FND_LEFT_PORT_Pin, GPIO_PIN_SET); \
								HAL_GPIO_WritePin(GPIOC, FND_RIGHT_PORT_Pin, GPIO_PIN_RESET); \
								HAL_GPIO_WritePin(FND_DOTC_PORT_GPIO_Port, FND_DOTC_PORT_Pin, GPIO_PIN_SET);\
								HAL_GPIO_WritePin(GPIOA, FND_DOT_PORT_Pin, GPIO_PIN_RESET);


#define	FND_COM_RIGHT_CLEAR		HAL_GPIO_WritePin(GPIOC, FND_RIGHT_PORT_Pin, GPIO_PIN_SET); \
								HAL_GPIO_WritePin(GPIOC, FND_LEFT_PORT_Pin, GPIO_PIN_RESET);

#define FND_SEG_NUM0_DISP	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
							  HAL_GPIO_WritePin(GPIOB, FND_G_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM1_DISP	  HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin|FND_C_PORT_Pin, GPIO_PIN_RESET); \
							  HAL_GPIO_WritePin(GPIOA, FND_A_PORT_Pin, GPIO_PIN_SET); \
							  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM2_DISP	  HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin, GPIO_PIN_SET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM3_DISP	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM4_DISP	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOA, FND_A_PORT_Pin, GPIO_PIN_SET); \
						      HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin|FND_D_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM5_DISP	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin, GPIO_PIN_SET); \
						      HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM6_DISP	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM7_DISP	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET); \

#define FND_SEG_NUM8_DISP	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET);

#define FND_SEG_NUM9_DISP	  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_G_PORT_Pin|FND_D_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin, GPIO_PIN_SET);
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */
uint8_t User_Button_Status = 0;
uint32_t g_ADC_Value;
unsigned char g_ADC1_Status = 0;
unsigned char Button_Status = 0;
uint32_t Button_Count = 0;
uint8_t FND_10disp = 0;
uint8_t FND_1disp = 0;
uint8_t FND_Status = 0;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
	void NUM_DISPLAY(uint8_t Disp_Seg_Num)
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

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	void Calculate_ADC1(uint32_t ADC1_Value)
	{
		uint8_t FND_Disp = 0;
		float FND_Value = 0;
		float V_REF = 3.3f;
		unsigned int ADC_Resolution = 4096;

		FND_Value = ((V_REF * ADC1_Value) / ADC_Resolution);

		FND_Disp = FND_Value * 10;

		FND_10disp = FND_Disp / 10;
		FND_1disp = FND_Disp % 10;
	}
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
  MX_ADC1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_ADC_Start_IT(&hadc1);
  HAL_TIM_Base_Start_IT(&htim3);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	          /*-----------------BUTTON CTRL OR ADC_IT_enable CTRL----------------------*/
	  if((HAL_GPIO_ReadPin(User_Button_GPIO_Port, User_Button_Pin) == PRESS_USER_BUTTON)&&(User_Button_Status == RELEASED_BUTTON)) 		// if button is push and user_button_status is released_button
	  {
		  Button_Count++;
		  if(Button_Count > MIN_BUTTON_COUNT) 				// if button_count greater than min_count
		  {
			  HAL_ADC_Start_IT(&hadc1);
		  }
      
		  User_Button_Status = PRESSED_BUTTON;
	  }

	  else if(HAL_GPIO_ReadPin(User_Button_GPIO_Port, User_Button_Pin)==RELEASE_USER_BUTTON)					// if button is release
	  {
		  Button_Count = BUTTON_COUNT_INITIALIZE;
		  User_Button_Status = RELEASED_BUTTON;
	  }


		  /*--------------ADC_Value calc--------------*/
	  if(g_ADC1_Status == INTERRUPT_OCCURRED)								// if g_ADC1_Status occurred INTERRUPT
	  {
		  Calculate_ADC1(g_ADC_Value);
		  g_ADC1_Status = INTERRUPT_WAITING;
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
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

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
  HAL_GPIO_WritePin(FND_DOTC_PORT_GPIO_Port, FND_DOTC_PORT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : User_Button_Pin */
  GPIO_InitStruct.Pin = User_Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(User_Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : FND_RIGHT_PORT_Pin FND_LEFT_PORT_Pin */
  GPIO_InitStruct.Pin = FND_RIGHT_PORT_Pin|FND_LEFT_PORT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : FND_C_PORT_Pin FND_B_PORT_Pin FND_A_PORT_Pin FND_DOT_PORT_Pin */
  GPIO_InitStruct.Pin = FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin|FND_DOT_PORT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : FND_DOTC_PORT_Pin FND_F_PORT_Pin FND_D_PORT_Pin FND_G_PORT_Pin
                           FND_E_PORT_Pin */
  GPIO_InitStruct.Pin = FND_DOTC_PORT_Pin|FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin
                          |FND_E_PORT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	g_ADC1_Status = INTERRUPT_OCCURRED;

	g_ADC_Value = HAL_ADC_GetValue(&hadc1);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim3)
	{
		if(FND_Status == FND_INITIALIZE)
		{
			FND_Status = FND_LEFT_ON;
			FND_COM_LEFT_CLEAR
			NUM_DISPLAY(FND_10disp);
		}

		else if(FND_Status == FND_LEFT_ON)
		{
			FND_Status = FND_RIGHT_ON;
			FND_COM_RIGHT_CLEAR
			NUM_DISPLAY(FND_1disp);
		}

		else
			FND_Status = FND_INITIALIZE;
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
