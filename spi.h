#ifndef SPI_H
#define SPI_H

//Includes
#include "main.h"

//Pin defines
#define NSS_SET GPIOA->BSRR = GPIO_BSRR_BS4
#define NSS_RESET GPIOA->BSRR = GPIOA_BSRR_BR4

//Functions
void SPI1_Init(void);
void SPI1_nrf24_GPIO_Init(void);

#endif