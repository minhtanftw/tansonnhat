#include <stdint.h>

typedef volatile struct {
    uint8_t TX_EN :1;
    uint8_t RX_EN :1;
    uint8_t BAUD_PRESC: 2;
    uint8_t PARITY_TYPE:1;
    uint8_t RSCD :2;
} UART_CR_BITS_t;

typedef union{
    uint8_t byte_access;
    UART_CR_BITS_t bits; 
}UART_CR_REG_t;

#define UART_CR (*(volatile UART_CR_REG_T *)0x40001000 )

void init_uart(void) {
    UART_CR.bits.TX_EN = 1;
    UART_CR.bits.RX_EN = 1;
    UART_CR.bits.BAUD_PRESC =0;
    UARt_CR.bits.PARITY= 0;

    if (UART_CR.bits.RX_EN){
        //
    }

    uint8_t cr_value = UART_CR.bye_access;
}

int main() {
    init_uart();
    return 0;
}