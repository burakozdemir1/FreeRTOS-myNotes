/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */


uint8_t myMessage[100];


xSemaphoreHandle xSemaphore = 		NULL;
xQueueHandle xQueue 		=		NULL ;
char *deneme = "Semaphore,Queue and Task Created...\r\n";



/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */








void Master_Task_Handler(void *params)
{
	// random sayılar elde edeceğiz

	unsigned int  xMasterPassId; // geçiş id si

	portBASE_TYPE xStatus; // kuyruğun durumunu sorgulamak için


	/*
	 	 sen ilk başya semafor oluşturdğunda bunun değeri 0 olarak başlar
	 	 önce bi 1 değeri ver ki o değer alınabilsin

	 */

//	xSemaphoreGive(xSemaphore); // ilk semafor anahtarını belirledik,yani anahtar aktif
	// sistemi başalatırken semafor anahtarını her zaman 1 yaparız
	//ile ilk çocuğa salıncak anahtarını verirsiniz

	/*


	 Başlangıçta semafor değeri 1 olacak şekilde ayarlanır.
	 Bu, Slave_Task_Handler görevinin semaforu alabilmesi için hazır hale getirilir.

	 Slave_Task_Handler kardeşime anahtarı kullanılabilir hale getirdim

	 yani bu fonks çağrıldğında semaforun değeri 1 olarak ayarlanır

	 eğer bu 1 olarak ayarlanmazsa Slave_Task_Handler görevindeki ;

	 xSemaphoreTake(xSemaphore, portMAX_DELAY); gibi bir fonksiyon çağrıldığında,
	  bu işlem semaforun değeri 1 olana kadar bekleyecektir

	 */




	while(1)
	{

		xMasterPassId = (rand() & 0x1FF); // xMasterPassId nesnesine bu oluşturduğum random değer gelir
		// bu random değerini kuyruğa yazarız

		xStatus = xQueueSend(xQueue,&xMasterPassId,portMAX_DELAY);

		/*
		 	 xQueue -> Mesajı göndermek istediğiniz kuyruğun tanıtıcısı
		 	 xMasterPassId -> Kuyruğa göndermek istediğiniz veri
		 	 portMAX_DELAY -> Kuyruk doluysa, görev kuyruğa mesaj göndermek için ne kadar süre bekleyecek,kuyruk dolana kadar beklemeyi seçiyoruz

		 */

		if(xStatus != pdPASS) // kuyruğa veri yazılmamıştır demek -> pdPASS, işlem başarılı demektir
		{
			sprintf((char*)myMessage,"Could not sent to the Queue!\r\n");
			HAL_UART_Transmit(&huart1, myMessage, strlen((char*)myMessage), 1000);
		}
		else
		{
		//	xSemaphoreGive(xSemaphore); // Semafor serbest bırakılır, BU GEREKSİZ TAMAMEN
		//diğer görevlerin (eğer varsa) o semaforu alabilmesi için sıra bekleyen görevlere izin verilir.
			// anahtarı almak için sırasını bekler
			//taskYIELD();
		}


	}


}


void Slave_Task_Handler(void *params)
{
	unsigned int xSlavePassId;

	portBASE_TYPE xStatus;


	while(1)
	{

		xSemaphoreTake(xSemaphore,0);
		/*

		 xSemaphoreTake -> belirtilen semaforu almak ve kullanmak için kullanılır.
		 xSemaphore, // Alınacak semaforun tanıtıcısı
		 0-> Semaforun alınması için maksimum bekleme süresidir.
		 	 anahtar yoksa  hemen almak istiyorsanız 0 verebilirsiniz

			İlk çocuk salıncaktan çıktığında,
			diğer çocuk xSemaphoreTake() ile anahtarı alır ve salıncakta oynamaya başlar.
		 */

		xStatus = xQueueReceive(xQueue, &xSlavePassId, 0);

		if(xStatus != pdPASS)
		{
			sprintf((char*)myMessage,"Slave Task: Queue is empty,nothing to do!\r\n");
			HAL_UART_Transmit(&huart1, myMessage, strlen((char*)myMessage), 1000);
		}
		else
		{
			SlaveDoWork(xSlavePassId);
		}
	}


}

void SlaveDoWork(unsigned int passId)
{
	sprintf((char*)myMessage,"Slave task working on Passed Id: %d \r\n",passId);
	HAL_UART_Transmit(&huart1, myMessage, strlen((char*)myMessage), 1000);
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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

	sprintf((char*)myMessage,"Demo of binary semaphore usage between two tasks.\r\n");


	HAL_UART_Transmit(&huart1, (uint8_t *)myMessage, strlen((char*)myMessage), 1000);


    xQueue = xQueueCreate(1,sizeof(unsigned int)) ; // kuyruk oluşturduk her seferinde 1 tane veri koyacağız
  	  	  	  	  	  	  	  	  	  	  	  	  // ve görev bu veriyi alıp tekrar 1 tane daha veri koyulacak

    vSemaphoreCreateBinary(xSemaphore); // semafor oluşturduk

 if( (xQueue!=NULL) && (xSemaphore!=NULL) )
  {
	  sprintf((char*)myMessage,"Semaphore,Queue and Task Created...\r\n");
	  HAL_UART_Transmit(&huart1, myMessage, strlen((char*)myMessage), 1000);
	  // semafor ve kuyruk sağlıklı bir şekilde oluştu mu diye kontrol ediyoruz


	  xTaskCreate(Master_Task_Handler, "Master_Task", 200, NULL, 3, NULL);
	  xTaskCreate(Slave_Task_Handler, "Slave_Task", 200, NULL, 2, NULL);

	  vTaskStartScheduler();
  }

  else
  {
	  sprintf((char*)myMessage,"Tasks are not created!\r\n");
	  HAL_UART_Transmit(&huart1, myMessage, sizeof((char*)myMessage), 1000);
  }











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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
