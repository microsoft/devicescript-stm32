#ifndef JD_USER_CONFIG_H
#define JD_USER_CONFIG_H

#include <stdint.h>

#define JD_DMESG_BUFFER_SIZE 4096

#define JD_LOG DMESG
#define JD_WR_OVERHEAD 28

#define JD_CLIENT 1

#define PIN_JACDAC 9

#define JD_RAW_FRAME 1

// this is min. erase size
#define JD_FLASH_PAGE_SIZE 4096

// probably not so useful on brains...
#define JD_CONFIG_WATCHDOG 0

#define JD_USB_BRIDGE 1

#define JD_SEND_FRAME_SIZE 1024

#define JD_LSTORE 0

#define JD_SETTINGS_LARGE 1

#define JD_FSTOR_TOTAL_SIZE (128 * 1024)
#define SPI_FLASH_MEGS 1

#define SPI_STORAGE_SIZE JD_FSTOR_TOTAL_SIZE
#define SPI_STORAGE_OFFSET (SPI_FLASH_MEGS * 1024 * 1024 - SPI_STORAGE_SIZE)
#define JD_FSTOR_BASE_ADDR (0x10000000 + SPI_STORAGE_OFFSET)

#define JD_DCFG_BASE_ADDR (JD_FSTOR_BASE_ADDR - 16 * 1024)

#define JD_I2C_HELPERS 1
// #define JD_HID 1

#endif
