#include "dsstm.h"

uint32_t now;

void app_init_services(void) {
    devs_service_full_init();
    if (i2c_init_() == 0) {
        jd_scan_all();
        i2cserv_init();
    }
}

uint32_t random_int(uint32_t max);

void *malloc(unsigned sz) {
    return jd_alloc(sz);
}

void free(void *p) {
    jd_free(p);
}

void *_malloc_r(struct _reent *r, size_t sz) {
    return jd_alloc(sz);
}

void _free_r(struct _reent *r, void *p) {
    jd_free(p);
}

void *_calloc_r(struct _reent *r, size_t a, size_t b) {
    return jd_alloc(a * b);
}

void *calloc(size_t a, size_t b) {
    return jd_alloc(a * b);
}

void __assert_func(const char *file, int line, const char *func, const char *failedexpr) {
    DMESG("expr: %s", failedexpr);
    jd_panic_core(file, line, func);
}

void __assert(const char *file, int line, const char *failedexpr) {
    __assert_func(file, line, NULL, failedexpr);
}

void platform_init(void) {
    tim_init();
    // adc_init_random();
    rtc_init();
    uart_init_();
    jd_init();

    usb_init();
    jd_usb_enable_serial();
}

int main(void) {
    platform_init();

    flash_sync();
    // link custom memcpy()
    random_int(1);

    while (true) {
        jd_process_everything();
#if JD_WIFI
        jd_tcpsock_process();
#endif
        if (!jd_rx_has_frame())
            __asm volatile("wfe");
    }
}

static void led_panic_blink(void) {
    pin_setup_output(PIN_LED);
    pin_setup_output(PIN_LED_GND);
    pin_set(PIN_LED_GND, 0);
    pin_set(PIN_LED, 1);
    target_wait_us(70000);
    pin_set(PIN_LED, 0);
    target_wait_us(70000);
}

void hw_panic(void) {
    DMESG("PANIC!");
    target_disable_irq();

    // if (CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk)
    //    __asm__ __volatile__("bkpt #0");

#ifdef JD_INFINITE_PANIC
    for (;;)
        led_panic_blink();
#else
    for (int i = 0; i < 60; ++i) {
        led_panic_blink();
    }
    target_reset();
#endif
}

int *__errno(void) {
    static int err;
    return &err;
}

void jd_crypto_get_random(uint8_t *trg, unsigned size) {
    JD_PANIC(); // not impl. yet
}

void power_pin_enable(int en) {}