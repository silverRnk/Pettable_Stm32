#include <stdint.h>
#include "stm32g431xx.h"

#define GPIOA_EN	(1U<<0);
#define GPIOC_EN	(1U<<2);

#define PA5_Output	(1)




void init_gpio(void);
void init_lpuart(void);

int main(void)
{
	// Init PA2 for LPUART tx
	init_gpio();
	while(1){
//		uint32_t x = GPIOC->IDR &(1<<13);
		if(GPIOC->IDR & (1U<<13)){
			GPIOA->ODR |= (1<<5);
		}else{
			GPIOA->BRR |= (1<<5);
		}
	}
}

void init_gpio(void){
	// En RCC AHB2 perip clk for GPIO A & C
	RCC->AHB2ENR |= GPIOA_EN;
	RCC->AHB2ENR |= GPIOC_EN;

	/* Init PA5 for control led pin*/
	// Select PA5 moder to output
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1<<11);

	// Init PC13 to control push button
	// Set PC13 moder to input;
	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);

	//Init PA2 moder to alt. func.
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	//Set PA2 to alt func. 12 (1100)
	GPIOA->AFR[0] &= ~(1U<<8);
	GPIOA->AFR[0] &= ~(1U<<9);
	GPIOA->AFR[0] &= ~(1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

}

void init_lpuart(void){
	//En transittion mode

	//En FIFO
	/** Configure the frame size **/
	//Set data frame to 8 bits
	//Set parity to 1
	//Set stop bit 1
	//Set baud rate

	//En the lpuart module

}
