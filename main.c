#include "uart.h"

int main(void) {
    UART_XbeeInit(115200);

    UART_XBeeWriteString("Hello from XBee\n");
    UART_XBeeWriteUint(12674);
    UART_XBeeWriteFloat(3.1415);

    while(1){

	}
}
