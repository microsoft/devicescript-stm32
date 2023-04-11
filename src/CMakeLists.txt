file(GLOB RUNNER_FILES *.c)

set(BASE_EXEC devsrunner)
set(EXECUTABLE devsrunner.elf)

add_executable(${EXECUTABLE}
    ${RUNNER_FILES}
    ${CMAKE_BINARY_DIR}/version.c
)

include_directories(AFTER
    "."
)

target_link_options(${EXECUTABLE} PRIVATE
        -T${STM32_CUBE_PATH}/Projects/B-L475E-IOT01A/Templates_LL/SW4STM32/B-L475E-IOT01/STM32L475VGTx_FLASH.ld
        ${ARCH_FLAGS}
        -specs=nano.specs
        -specs=nosys.specs
        -lm
        -Wl,-Map=${EXECUTABLE}.map,--cref
        -Wl,--gc-sections
        )

target_link_libraries(${EXECUTABLE} PUBLIC
    jacdac
    devicescript
    jacdac-stm32
)

add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-size ${EXECUTABLE})

add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex ${EXECUTABLE} ${BASE_EXEC}.hex
        COMMAND arm-none-eabi-objcopy -O binary ${EXECUTABLE} ${BASE_EXEC}.bin)
