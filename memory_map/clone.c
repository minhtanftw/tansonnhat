#include <stdint.h>

typedef struct{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinSpeed;        // 0: Low, 1: Medium, 2: Fast, 3: High
	uint8_t GPIO_PinInputMode;    // 0: No Pull, 1: Pull-up, 2: Pull-down
	uint8_t GPIO_PinOutputMode;   // 0: Push-pull, 1: Open-drain
	uint8_t GPIO_PinAlternate;    // AF0 - AF15 (nếu dùng Alternate Function)
	uint8_t EXTI_Mode;            // 0: Không dùng EXTI, 1: Rising, 2: Falling, 3: Both
} GPIO_PinConfigType;


void GPIOA_init(const GPIO_PinConfigType*pUserConfig) {
    uint8_t pin = pUserConfig ->GPIO_PinNumber;

    volatile  uint32_t *GPIOA_MODER = (uint32_t *)0x40002000;
    *GPIOA_MODER &= ~(0x3 <<  pin *2); //Clear

    *GPIOA_MODER |= (pUserConfig->GPIO_PinMode << (pin *2));

    //OTYER-Offset 0x04
    volatile uint32_t *GPIOA_OTYER = (uint32_t *)0x4002004;
    *GPIOA_OTYPER &= ~(1 << pin);
    *GPIOA_OTYPER |= (pUSerConfig->GPIO_PinOutputMode) << pin;


    volatile uint32_t *GPIOA_OSPEER =(uint32_t *)0x4002008;
    *GPIOA_OSPEER &= ~(0x03 << (pin *2));
    *GPIOA_OSPEER |= (pUserConfig ->GPIO_PinSpeed << (pin *2));

    volatile uint32_t *GPIOA_PUDR = (uint32_t *) 0x400200C;
    *GPIOA_PUDR &= (0x03 <<(pin *2));
    *GPIOA_PUDR |= (pUserConfig->GPIO_PinInputMode  <<( pin *2));

}

int main() {
    GPIO_PinConfigType  ledPinConfig;
    ledPinConfig.GPIO_PinNumber     = 5;  // PA5
	ledPinConfig.GPIO_PinMode       = 1;  // Output
	ledPinConfig.GPIO_PinSpeed      = 2;  // Fast speed
	ledPinConfig.GPIO_PinInputMode  = 0;  // No pull-up/pull-down
	ledPinConfig.GPIO_PinOutputMode = 0;  // Push-pull
	ledPinConfig.GPIO_PinAlternate  = 0;  // Not used
	ledPinConfig.EXTI_Mode          = 0;  // Not used

    //Cau hinh enable cho FPGA
    volatile uint32_t *RCC_AHB1ENR = (uint32_t *)0x4002380;
    *RHC_AHB1ENR |= (1<<0);
    volatile uint32_t *GPIOA_ODR  = (uint32_t *)0x40020014;
    *GPIOA_ODR |= (1<<5);
    return 0;
}