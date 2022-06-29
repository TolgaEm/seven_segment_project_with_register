
#include "main.h"
#include "led_init.h"
#include "button_init.h"

void SystemClock_Config(void);

uint8_t counter=0;

int main(void)
{
	
  HAL_Init();	
  SystemClock_Config();
  button_init();
  led_init();

  while (1)
  {
	  if (GPIOB->IDR == 1){
		  HAL_Delay(100);
		  counter++;

		  switch (counter) {

		  case 1:
			  GPIOA->ODR |= 0X00000006; // 1 STATE ON THE DİSPLAY
			  break;
		  case 2:
			  GPIOA->ODR |= 0X0000005B; // 2 STATE ON THE DİSPLAY
			  break;
		  case 3:
			  GPIOA->ODR |= 0X0000005F; // 3 STATE ON THE DİSPLAY
			  break;
		  case 4:
			  GPIOA->ODR |= 0X00000038; // 4 STATE ON THE DİSPLAY
			  break;
		  case 5:
			  GPIOA->ODR |= 0X0000006D; // 5 STATE ON THE DİSPLAY
			  break;
		  case 6:
			  GPIOA->ODR |= 0X0000007C; // 6 STATE ON THE DİSPLAY
			  break;
		  case 7:
			  GPIOA->ODR |= 0X00000007; // 7 STATE ON THE DİSPLAY
			  break;
		  case 8:
			  GPIOA->ODR |= 0X0000007F; // 8 STATE ON THE DİSPLAY
			  break;
		  case 9:
			  GPIOA->ODR |= 0X0000006F; // 9 STATE ON THE DİSPLAY
			  break;

		  default:
			  if (counter == 10){
				  counter=1;
				  GPIOA->ODR |= 0X00000006;
			  }
		  }
	  }
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

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
