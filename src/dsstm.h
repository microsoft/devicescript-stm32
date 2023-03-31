#pragma once

#include "jd_client.h"
#include "devicescript.h"
#include "pinnames.h"
#include "services/jd_services.h"
#include "services/interfaces/jd_pins.h"
#include "services/interfaces/jd_flash.h"

void init_devicescript_manager(void);
void jd_tcpsock_process(void);
uint32_t hw_random(void);

void usb_init(void);

void reboot_to_uf2(void);

void platform_init(void);
