#ifndef JD_USER_CONFIG_H
#define JD_USER_CONFIG_H

#include <stdint.h>

#define JD_DMESG_BUFFER_SIZE 4096

#define JD_LOG DMESG
#define JD_WR_OVERHEAD 28

#define JD_CLIENT 1

#define JD_RAW_FRAME 1

// this is min. erase size
#define JD_FLASH_PAGE_SIZE 4096

// probably not so useful on brains...
#define JD_CONFIG_WATCHDOG 0

#define JD_USB_BRIDGE 1

#define JD_SEND_FRAME_SIZE 1024

#define JD_LSTORE 0

#define JD_SETTINGS_LARGE 1

#define FLASH_KB 1024
#define JD_FSTOR_TOTAL_SIZE (128 * 1024)
#define FLASH_STORAGE_OFFSET (FLASH_KB * 1024 - JD_FSTOR_TOTAL_SIZE)
#define JD_FSTOR_BASE_ADDR (0x08000000 + FLASH_STORAGE_OFFSET)

#define JD_DCFG_BASE_ADDR (JD_FSTOR_BASE_ADDR - 16 * 1024)

#define JD_HW_ALLOC 1
#define JD_STACK_SIZE 4096

#define JD_I2C_HELPERS 1
// #define JD_HID 1

#define PIN_SCL PB_10
#define PIN_SDA PB_11
#define I2C_AF LL_GPIO_AF_4
#define I2C_IDX 2

#define PIN_JACDAC PA_0 // D1
#define USART_IDX 4
#define UART_PIN PIN_JACDAC
#define UART_PIN_AF 8

// PC_13 blue button
// PB_14 also LED
#define PIN_LED PA_5
#define PIN_LED_GND NO_PIN

#define JD_ANALOG 0

#define JD_FSTOR_MAX_DATA_PAGES (512 / 4)

#endif
