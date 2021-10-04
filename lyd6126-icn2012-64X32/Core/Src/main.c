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


uint16_t TOnLP;
uint8_t RAW_DISPLAY[3][256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 124, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 113, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 113, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 17, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 119, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void digitalWrite(GPIO_TypeDef * Port, uint16_t NumP, uint8_t  stat) {
if(stat){
	HAL_GPIO_WritePin(Port, NumP, GPIO_PIN_SET);
}else{
	HAL_GPIO_WritePin(Port, NumP, GPIO_PIN_RESET);
}
}

void SetBrightness(uint16_t Panel_Brightness) {
  TOnLP = Panel_Brightness;
}

void LoadAndShowBufOnPanel(void) {
  uint8_t i_m;
  uint8_t bit_mask;
	uint8_t y_b;
	uint8_t x_b;
  for (y_b = 0; y_b < 8; y_b++) {
    digitalWrite(GPIOB,OE_LED_Pin, 1);
    digitalWrite(GPIOB,LAT_LED_Pin, 0);
    for (x_b = 0; x_b < 128; x_b++) {
      bit_mask = 1 << (x_b % 8);
      i_m = (y_b * 16) + (x_b / 8);
      digitalWrite(GPIOB,CLK_LED_Pin, 0);
      digitalWrite(R1_LED_GPIO_Port,R1_LED_Pin, RAW_DISPLAY[0][i_m] & bit_mask);
      digitalWrite(GPIOD,G1_LED_Pin, RAW_DISPLAY[1][i_m] & bit_mask);
      digitalWrite(GPIOD,B1_LED_Pin, RAW_DISPLAY[2][i_m] & bit_mask);
      i_m += 128;
      digitalWrite(GPIOD,R2_LED_Pin, RAW_DISPLAY[0][i_m] & bit_mask);
      digitalWrite(GPIOD,G2_LED_Pin, RAW_DISPLAY[1][i_m] & bit_mask);
      digitalWrite(GPIOB,B2_LED_Pin, RAW_DISPLAY[2][i_m] & bit_mask);
      digitalWrite(GPIOB,CLK_LED_Pin, 1);
      if (x_b == 125) {
        digitalWrite(GPIOB,LAT_LED_Pin, 1);
      }
    }
    digitalWrite(GPIOB,A_Line_Pin, (y_b & 0b1)>0);
    digitalWrite(GPIOB,B_Line_Pin, (y_b & 0b10)>0);
    digitalWrite(GPIOB,C_Line_Pin, (y_b & 0b100)>0);
    digitalWrite(GPIOB,OE_LED_Pin, 0);
    HAL_Delay(TOnLP);
  }
}

void SetPixel(uint8_t Xp, uint8_t Yp, uint8_t Color3) {
  uint8_t adr[] = {8, 24, 40, 56, 72, 88, 104, 120, 0, 16, 32, 48, 64, 80, 96, 112};
  uint32_t Red_p = 0;
  uint32_t Green_p = 0;
  uint32_t Blue_p = 0;
  if (Yp < 16) {
    Yp = adr[Yp] + (Xp / 8);
  } else {
    Yp = adr[Yp - 16] + (Xp / 8) + 128;
  }
  Xp %= 8;
  if (Color3 & 0b100) {
    Red_p = 1 << Xp;
  }
  if (Color3 & 0b10) {
    Green_p = 1 << Xp;
  }
  if (Color3 & 0b1) {
    Blue_p = 1 << Xp;
  }
  if (!(RAW_DISPLAY[0][Yp] & Red_p)) {
    if (Red_p) {
      RAW_DISPLAY[0][Yp] |= Red_p;
    }
    else {
      RAW_DISPLAY[0][Yp] &= ~(1 << Xp);
    }
  }
  if (!(RAW_DISPLAY[1][Yp] & Green_p)) {
    if (Green_p) {
      RAW_DISPLAY[1][Yp] |= Green_p;
    }
    else {
      RAW_DISPLAY[1][Yp] &= ~(1 << Xp);
    }
  }
  if (!(RAW_DISPLAY[2][Yp] & Blue_p)) {
    if (Blue_p) {
      RAW_DISPLAY[2][Yp] |= Blue_p;
    }
    else {
      RAW_DISPLAY[2][Yp] &= ~(1 << Xp);
    }
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

  SetBrightness(10); //0-65535
  SetPixel(10, 0, 6); //x=10, y=0, color=6=0b110-RGB: R+G=Yellow
  SetPixel(11, 1, 1);
  SetPixel(12, 2, 2);
  SetPixel(13, 3, 3);
  SetPixel(14, 4, 4);
  SetPixel(15, 5, 5);
  SetPixel(16, 6, 7);
  SetPixel(17, 7, 0);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(R1_LED_GPIO_Port, R1_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, G1_LED_Pin|B1_LED_Pin|R2_LED_Pin|G2_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, B2_LED_Pin|A_Line_Pin|B_Line_Pin|C_Line_Pin
                          |CLK_LED_Pin|OE_LED_Pin|LAT_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : R1_LED_Pin */
  GPIO_InitStruct.Pin = R1_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(R1_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : G1_LED_Pin B1_LED_Pin R2_LED_Pin G2_LED_Pin */
  GPIO_InitStruct.Pin = G1_LED_Pin|B1_LED_Pin|R2_LED_Pin|G2_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : B2_LED_Pin A_Line_Pin B_Line_Pin C_Line_Pin
                           CLK_LED_Pin OE_LED_Pin LAT_LED_Pin */
  GPIO_InitStruct.Pin = B2_LED_Pin|A_Line_Pin|B_Line_Pin|C_Line_Pin
                          |CLK_LED_Pin|OE_LED_Pin|LAT_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
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
