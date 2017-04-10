#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#define RX_BUFFER_SIZE  128

void UART_XbeeInit(uint32_t baud_rate);
void UART_XBeeWriteBytes(uint8_t *data, uint32_t size);
void UART_XBeeWriteString(const char *string);
void UART_XBeeRead(uint8_t *data, uint32_t size);

#endif /* UART_H_ */
