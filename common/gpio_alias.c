#include "gpio_alias.h"
#include "gpio.h"
#include "exti.h"
#include <string.h>

const GPIO GPIO_TABLE[] = {
	
	/* STM32F767ZI */
	FILL_GPIO("JTDI",			GPIOA, 15, ALT, LOW_SPEED, PULL_UP, false, OTHER)
	FILL_GPIO("SWCLK",			GPIOA, 14, ALT, VERY_HIGH_SPEED, PULL_DOWN, false, OTHER)
	FILL_GPIO("SWDAT",			GPIOA, 13, ALT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("NJTRST",			GPIOB,  4, ALT, LOW_SPEED, PULL_UP, false, OTHER)
	FILL_GPIO("JTDO",			GPIOB,  3, ALT, VERY_HIGH_SPEED, NONE, false, OTHER)
	FILL_GPIO("OSC_IN",			GPIOH,  0, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("OSC_OUT",		GPIOH,  1, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("LSE_IN",			GPIOC, 14, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("LSE_OUT",		GPIOC, 15, INPUT, LOW_SPEED, NONE, false, OTHER)

	/* Nucleo 144 I/O */
	FILL_GPIO("REDLED",			GPIOB, 14, OUTPUT, LOW_SPEED, NONE, true, LED)
	FILL_GPIO("BLUELED",		GPIOB,  7, OUTPUT, LOW_SPEED, NONE, true, LED)
	FILL_GPIO("GREENLED",		GPIOB,  0, OUTPUT, LOW_SPEED, NONE, true, LED)
	FILL_GPIO("BUTTON",			GPIOC, 13,  INPUT, LOW_SPEED, NONE, true, LED)

	/* Nucleo 144 USB USART */
	FILL_AFIO("UART TX",		GPIOD, 8, ALT, 7, HIGH_SPEED, NONE, true, OTHER)
	FILL_AFIO("UART RX",		GPIOD, 9, ALT, 7, HIGH_SPEED, NONE, true, OTHER)

	/*	Nucleo 144 USB */
	FILL_GPIO("USB SOF",		GPIOA,  8, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("USB VBUS",		GPIOA,  9, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("USB ID",			GPIOA, 10, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("USB DM",			GPIOA, 11, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("USB DP",			GPIOA, 12, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("USB GPIO OUT",	GPIOG,  6, INPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("USB GPIO IN",	GPIOG,  7, INPUT, LOW_SPEED, NONE, false, OTHER)

	/* Nucleo 144 Ethernet */
	FILL_GPIO("RMII REFCLK",	GPIOA, 1, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("RMII MDIO",		GPIOA, 2, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("RMII MDC",		GPIOC, 1, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("RMII RX DV",		GPIOA, 7, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("RMII RXD0",		GPIOC, 4, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("RMII RXD1",		GPIOC, 5, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("RMII TX EN",		GPIOG, 11, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("RMII TXD0",		GPIOG, 13, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("RMII TXD1",		GPIOB, 13, OUTPUT, LOW_SPEED, NONE, false, OTHER)
	/* Application I/O */
	/* INPUT */
	FILL_GPIO("LIMITSWITCH1",		GPIOG,  2, INPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("LIMITSWITCH2",		GPIOG,  3, INPUT, LOW_SPEED, NONE, true, SOLENOID)

	/* OUTPUT */
	FILL_GPIO("GPIO1",		GPIOD,  0, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO2",		GPIOD,  1, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO3",		GPIOD,  3, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO4",		GPIOD,  4, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO5",		GPIOD,  5, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO6",		GPIOD,  6, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO7",		GPIOD,  7, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO8",		GPIOE,  14, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO9",		GPIOF,  12, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO10",		GPIOG,  0, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO11",		GPIOG,  1, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO12",		GPIOF,  13, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	FILL_GPIO("GPIO13",		GPIOF,  14, OUTPUT, LOW_SPEED, NONE, true, SOLENOID)
	
	/* Application Analog */
	FILL_GPIO("Analog1",		GPIOA,  3, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog2",		GPIOB,  1, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog3",		GPIOC,  0, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog4",		GPIOC,  2, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog5",		GPIOC,  3, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog6",		GPIOF,  3, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog7",		GPIOF,  4, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog8",		GPIOF,  5, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog9",		GPIOF,  10, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog10",		GPIOF,  6, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog11",		GPIOF,  7, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog12",		GPIOF,  8, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog13",		GPIOF,  9, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog14",		GPIOA,  4, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog15",		GPIOA,  5, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog16",		GPIOA,  6, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	FILL_GPIO("Analog17",		GPIOF,  11, ANALOG, LOW_SPEED, NONE, true, PRESSURE)
	
	/* Application PWM TIM2*/
	/*Ch 1*/
	FILL_AFIO("PWM1",		GPIOA,  0, ALT, 1, LOW_SPEED, NONE, true, SOLENOID)
	/*Ch 3*/
	FILL_AFIO("PWM2",		GPIOB,  10, ALT, 1, LOW_SPEED, NONE, true, SOLENOID)
	/*Ch 4*/
	FILL_AFIO("PWM3",		GPIOB,  11, ALT, 1, LOW_SPEED, NONE, true, SOLENOID) 
	
	/* Application EXTI */
	FILL_AFIO("Retro1",		GPIOE,  9, ALT, 1, LOW_SPEED, NONE, true, RETRO)
	FILL_AFIO("Retro2",		GPIOE, 11, ALT, 1, LOW_SPEED, NONE, true, RETRO)
	FILL_AFIO("Retro3",		GPIOE, 13, ALT, 1, LOW_SPEED, NONE, true, RETRO)

	/* Application I2C */
	FILL_AFIO("SDA",		GPIOF, 0, ALT, 4, LOW_SPEED, NONE, true, I2C)
	FILL_AFIO("SCL",		GPIOF, 1, ALT, 4, LOW_SPEED, NONE, true, I2C)

	/* Application SDMMC */
	FILL_GPIO("SDMMC1 D0",		GPIOC,  8, ALT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("SDMMC1 D1",		GPIOC,  9, ALT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("SDMMC1 D2",		GPIOC, 10, ALT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("SDMMC1 D3",		GPIOC, 11, ALT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("SDMMC1 CK",		GPIOC, 12, ALT, LOW_SPEED, NONE, false, OTHER)
	FILL_GPIO("SDMMC1 CMD",		GPIOD,  2, ALT, LOW_SPEED, NONE, false, OTHER)
};

const uint8_t NUM_GPIO_ALIAS = sizeof(GPIO_TABLE)/sizeof(GPIO);
const char * GROUP_NAMES[] = {"other", "sensors", "solenoid", "retro", "led", "i2c", "PRESSURE"};
const uint8_t NUM_GROUPS = sizeof(GROUP_NAMES)/sizeof(char *);

int gpioAliasInit(){
	int i;
	GPIO_TypeDef * port;
	uint8_t pin;

	for(i =0; i < NUM_GPIO_ALIAS; i++){
		if (GPIO_TABLE[i].usable){
			port = GPIO_TABLE[i].port;
			pin = GPIO_TABLE[i].pin;

			gpio_setClock(port, true);
			gpio_setMode(port, pin, GPIO_TABLE[i].mode);
			gpio_setSpeed(port, pin, GPIO_TABLE[i].speed);
			
			if (GPIO_TABLE[i].mode == ALT)
				gpio_setAlternateFunc(port, pin, GPIO_TABLE[i].af_val);
			
			if (GPIO_TABLE[i].group == I2C)
				gpio_openDrainState(port, pin, true);

			if (GPIO_TABLE[i].group == RETRO)
				exti_config(port, pin, true, false, true);

			if (GPIO_TABLE[i].mode == OUTPUT)
				gpio_writePin(port, pin, 0);
		}
	}

	return 0;
}

int hasGpioAlias(GPIO_TypeDef ** port, uint8_t * pin, char * name) {
	int i;
	for (i = 0; i<NUM_GPIO_ALIAS;i++){
		if (strcmp(GPIO_TABLE[i].name, name)==0) {
			*pin = GPIO_TABLE[i].pin;
			*port = GPIO_TABLE[i].port;
			return 1;
		}
	}
	return 0;
}

int getGpioAlias(GPIO_TypeDef ** port, uint8_t * pin, GPIO * alias) {
	int i; 
	for (i = 0; i<NUM_GPIO_ALIAS; i++){
		if (GPIO_TABLE[i].pin == *pin && GPIO_TABLE[i].port == *port) {
			*alias=	GPIO_TABLE[i];
			return 1;
		}	
	}
	return 0;

}



