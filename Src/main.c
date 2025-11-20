// PA5 - LED
// 0x4800 0000 - GPIOA
// 0x4002 1000 - RCC
#include <stdint.h>
#define RCC_BASE_ADDR 0x40021000U
#define GPIO_BASE_ADDR 0x48000000U

#define RCC_AHBENR_OFFSET 0x14U
#define RCC_AHBENR_REG    (*(unsigned int volatile *)(RCC_BASE_ADDR + RCC_AHBENR_OFFSET))

#define GPIOA_MODER_OFFSET 0x00U
#define GPIOA_MODER_REG    (*(unsigned int volatile *)(GPIO_BASE_ADDR + GPIOA_MODER_OFFSET))

#define GPIOA_ODR_OFFSET  0x14U
#define GPIOA_ODR_REG     (*(unsigned int volatile *)(GPIO_BASE_ADDR + GPIOA_ODR_OFFSET))

void delay(volatile uint32_t d)
{
	while(d--);
}


int main(void)
{
	RCC_AHBENR_REG |= (1U << 17);

	GPIOA_MODER_REG |= (1U << 10);
	GPIOA_MODER_REG &= ~(1U << 11);


	while(1)
	{
	GPIOA_ODR_REG |= (1U << 5);
	delay(500000);

	GPIOA_ODR_REG &= ~(1U << 5);
	delay(500000);
	}
	return 0;
}
