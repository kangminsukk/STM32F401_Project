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

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define HIGH	1
#define LOW		0
#define PRSEE	0
#define TAKE_IT_OFF		1
#define MAX_COUNT	80
#define MIN_COUNT 	1
#define COUNT		Button_Count

#define	FND_COM_LEFT_SET		HAL_GPIO_WritePin(GPIOC, FND_RIGHT_PORT_Pin, GPIO_PIN_RESET); \
								HAL_GPIO_WritePin(GPIOC, FND_LEFT_PORT_Pin, GPIO_PIN_SET);

#define	FND_COM_RIGHT_SET		HAL_GPIO_WritePin(GPIOC, FND_LEFT_PORT_Pin, GPIO_PIN_RESET); \
								HAL_GPIO_WritePin(GPIOC, FND_RIGHT_PORT_Pin, GPIO_PIN_SET);

#define FND_SEG_NUM0_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
							  HAL_GPIO_WritePin(GPIOB, FND_G_PORT_Pin, GPIO_PIN_SET);}

#define FND_SEG_NUM1_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin|FND_C_PORT_Pin, GPIO_PIN_RESET); \
							  HAL_GPIO_WritePin(GPIOA, FND_A_PORT_Pin, GPIO_PIN_SET); \
							  HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET);}

#define FND_SEG_NUM2_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin, GPIO_PIN_SET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin, GPIO_PIN_SET);}

#define FND_SEG_NUM3_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET);}

#define FND_SEG_NUM4_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOA, FND_A_PORT_Pin, GPIO_PIN_SET); \
						      HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin|FND_D_PORT_Pin, GPIO_PIN_SET);}

#define FND_SEG_NUM5_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin, GPIO_PIN_SET); \
						      HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin, GPIO_PIN_SET);}

#define FND_SEG_NUM6_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOA, FND_B_PORT_Pin, GPIO_PIN_SET);}

#define FND_SEG_NUM7_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_SET); }

#define FND_SEG_NUM8_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin, GPIO_PIN_RESET);}

#define FND_SEG_NUM9_DISP	  {HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_F_PORT_Pin|FND_G_PORT_Pin|FND_D_PORT_Pin, GPIO_PIN_RESET); \
						      HAL_GPIO_WritePin(GPIOB, FND_E_PORT_Pin, GPIO_PIN_SET);}

void FND_SEG_CTRL(unsigned char Disp_Seg_Num)   				 /* ???????????? ?????? void ?????? FND_SEG_CTRL ?????? ?????? ?????? () ??????
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 unsigned char ??? disp_seg_num ?????? ??????????????? ?????? ?????? ?????? ??? ??????*/
{
	switch(Disp_Seg_Num)										// switch ?????? () ?????? disp_seg_num ????????? ??????.
	{
	case 0:														// case 0 ??? ???
		FND_SEG_NUM0_DISP										// FND_SEG_NUM0_DISP ????????? ??????.
		break;													// ??????.
	case 1:														// case 1 ??? ???
		FND_SEG_NUM1_DISP										// FND_SEG_NUM1_DISP ????????? ??????.
		break;													// ??????.
	case 2:														// case 2 ??? ???
		FND_SEG_NUM2_DISP										// FND_SEG_NUM2_DISP ????????? ??????.
		break;													// ??????.
	case 3:														// case 3 ??? ???
		FND_SEG_NUM3_DISP										// FND_SEG_NUM3_DISP ????????? ??????.
		break;													// ??????.
	case 4:														// case 4 ??? ???
		FND_SEG_NUM4_DISP										// FND_SEG_NUM4_DISP ????????? ??????.
		break;													// ??????.
	case 5:														// case 5 ??? ???
		FND_SEG_NUM5_DISP										// FND_SEG_NUM5_DISP ????????? ??????.
		break;													// ??????.
	case 6:														// case 6 ??? ???
		FND_SEG_NUM6_DISP										// FND_SEG_NUM6_DISP ????????? ??????.
		break;													// ??????.
	case 7:														// case 7 ??? ???
		FND_SEG_NUM7_DISP										// FND_SEG_NUM7_DISP ????????? ??????.
		break;													// ??????.
	case 8:														// case 8 ??? ???
		FND_SEG_NUM8_DISP										// FND_SEG_NUM8_DISP ????????? ??????.
		break;													// ??????.
	case 9:														// case 9 ??? ???
		FND_SEG_NUM9_DISP										// FND_SEG_NUM0_DISP ????????? ??????.
		break;													// ??????.
	}
}

void FND_Display(unsigned char Disp_Num)						/* ???????????? ?????? void ??? FND_Display()?????? ?????????
																   unsigned char disp_num ?????? ??????????????? ?????? ????????? ?????? ??? ??????*/
{
	unsigned char Disp10 = 0;									// unsigned char ??? disp10 ????????? ????????? 0 ?????? ?????? ?????????
	unsigned char Disp1 = 0;									// unsigned char ??? disp1 ????????? ????????? 0 ?????? ?????? ?????????

	Disp10 = Disp_Num/10;										// disp_num ??? 10??? ?????? ?????? disp10 ?????? ????????? ??????
	Disp1 = Disp_Num%10;										// disp_num ??? 10??? ?????? ?????? disp1 ?????? ????????? ??????

	FND_COM_RIGHT_SET											// ??????FND ??? ?????? ????????? FND??? ??????.
	FND_SEG_CTRL(Disp1);										// FND_SEG_CTRL() ????????? ()?????? disp1 ????????? ????????? ????????? ??????.
	HAL_Delay(0.1);												// Delay() 0.1ms ???.

	FND_COM_LEFT_SET											// ?????????FND ??? ?????? ?????? FND??? ??????.
	FND_SEG_CTRL(Disp10);										// FND_SEG_CTRL() ????????? ()?????? disp10 ????????? ????????? ????????? ??????.
	HAL_Delay(0.1);												// Delay() 0.1ms ???.
}
static unsigned char Button_Count = 0;
void FND_Table()							/* ???????????? ?????? void ??? FND_Table()?????? ?????????
  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  unsigned char fnd_count ?????? ??????????????? ?????? ????????? ?????? ??? ????????? ?????? main ???????????? ????????? ?????? ?????????. */
{
	static unsigned char Mull = 2;  									// unsgined char ??? Mull ????????? ????????? 2 ?????? ?????? ?????????
	unsigned char Fnd_Count = 0;
																// unsigned char ??? Fnd_number ????????? ????????? 0????????? ?????? ?????????
	Mull += COUNT / 10;										// Mull = Mull + (fnd_count / 10) ?????? ??????
	if(Mull == 10)
	{
		Mull = 2;
	}

	if(COUNT == 80)
	{
		COUNT = 1;
	}

	Fnd_Count = Mull*COUNT;								// Mull ??? fnd_count ??? ?????? ?????? Fnd_number?????? ????????? ??????
    FND_Display(Fnd_Count);									// FND_Display()?????? ????????? Fnd_number ?????? ?????? ??????
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	unsigned char Push_Button = 0;								// unsigned char ??? button_max_count ?????? ????????? 0 ?????? ?????? ?????????
	unsigned char Button_Count = 0;								// usnigned char ??? button_count ?????? ????????? 0 ?????? ?????? ?????????
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //????????? ???????????????  ????????? ?????? ??? ?????? ????????? ?????? 2????????? 9?????????.
      if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)==PRSEE)    						// ?????? ????????? ???????????? button_max_count ?????? 1??? ??????
	  {
		  Push_Button = HIGH;
	  }

	  else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)==TAKE_IT_OFF)				// ?????? ????????? ????????? ????????????
	  {
		  if(Push_Button == HIGH)														// ????????? ?????? ???????????? button_max_count ?????? 1?????????
		  {
			  COUNT++;
		  }
		  Push_Button = LOW;													// buttn_max_button ?????? 0??? ??????.
	  }
     FND_Table(COUNT);
     													// ?????? FND_Table() ?????? ?????? button_count ????????? ?????? ??????.
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
  HAL_GPIO_WritePin(GPIOA, FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin, GPIO_PIN_SET);

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

  /*Configure GPIO pins : FND_C_PORT_Pin FND_B_PORT_Pin FND_A_PORT_Pin */
  GPIO_InitStruct.Pin = FND_C_PORT_Pin|FND_B_PORT_Pin|FND_A_PORT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : FND_F_PORT_Pin FND_D_PORT_Pin FND_G_PORT_Pin FND_E_PORT_Pin */
  GPIO_InitStruct.Pin = FND_F_PORT_Pin|FND_D_PORT_Pin|FND_G_PORT_Pin|FND_E_PORT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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
