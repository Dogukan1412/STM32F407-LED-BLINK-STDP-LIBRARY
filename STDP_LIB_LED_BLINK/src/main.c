
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void Delay(uint32_t time);
void GPIO_Config(void);  /* User leds --> D12,D13,D14,D15 */

GPIO_InitTypeDef Led;

int main(void)
{
	GPIO_Config();
  while (1)
  {
	  GPIO_SetBits(GPIOD, GPIO_Pin_All);
	  Delay(21000000); // 21000000 = 1 second
	  GPIO_ResetBits(GPIOD, GPIO_Pin_All);
	  Delay(21000000); // 21000000 = 1 second
  }
}


void GPIO_Config(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);  // activated the D port clock buss

	Led.GPIO_Mode = GPIO_Mode_OUT;
	Led.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	Led.GPIO_PuPd = GPIO_PuPd_NOPULL;
	Led.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOD, &Led);  // configuration is initialized
}

void Delay(uint32_t time)
{
	while(time--);
}







/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
