#include "spi.h"

void SPI1_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN; //SPI clocking
	
	SPI1->CR1 = 0; //reset all CR1 registers
	
	SPI1->CR1 |= SPI_CR1_BR_1; // 72000000 / 16 = 4.5 MHz
	SPI1->CR1 &= ~(SPI_CR1_BIDIMODE | SPI_CR1_RXONLY); //2-line unidirectional data mode, full duplex
	SPI1->CR1 &= ~(SPI_CR1_CPOL | SPI_CR1_CPHA); //[0;0] mode (CPOL - 0, CPHA - 0)
	SPI1->CR1 &= ~SPI_CR1_LSBFIRST; //MSB first
	SPI1->CR1 &= ~SPI_CR1_DFF; //8 bit
	SPI1->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI; //Software slave management enable
	SPI1->CR1 |= SPI_CR1_MSTR; //Master configuration
	
	SPI1->CR2 = 0; //reset all CR2 registers
	
	SPI1->CR1 |= SPI_CR1_SPE; //SPI enable
}

void SPI1_nrf24_GPIO_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN; //IOPBEN clocking for IRQ and CE(PB0)
	
	//PA4 - NSS(CS), general purpose output push-pull, 50 MHz
	GPIOA->CRL |= GPIO_CRL_MODE4;
	GPIOA->CRL &= ~GPIO_CRL_CNF4;
	NSS_SET;
	//PA5 - SCK, AF output Push-pull, 50 MHz
	GPIOA->CRL |= GPIO_CRL_MODE5;
	GPIOA->CRL &= ~GPIO_CRL_CNF5;
	GPIOA->CRL |= GPIO_CRL_CNF5_1;
	//PA6 - MISO, floating input
	GPIOA->CRL &= ~GPIO_CRL_MODE6;
	GPIOA->CRL &= ~GPIO_CRL_CNF6;
	GPIOA->CRL |= GPIO_CRL_CNF6_0;
	//PA7 - MOSI, AF output Push-pull, 50 MHz
	GPIOA->CRL |= GPIO_CRL_MODE7;
	GPIOA->CRL &= ~GPIO_CRL_CNF7;
	GPIOA->CRL |= GPIO_CRL_CNF7_1;
	//PB0 - CE, general purpose output push-pull, 50 MHz
	GPIOB->CRL |= GPIO_CRL_MODE0;
	GPIOB->CRL &= ~GPIO_CRL_CNF0;
}