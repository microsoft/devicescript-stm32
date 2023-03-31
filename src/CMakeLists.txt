file(GLOB RUNNER_FILES *.c)

add_executable(devsrunner
    ${RUNNER_FILES}
    ${CMAKE_BINARY_DIR}/version.c
)

include_directories(AFTER
    "."
)

target_link_libraries(devsrunner PUBLIC
    CMSIS::STM32::${FAMILY}
    STM32::NoSys
    STM32::Nano
    jacdac
    devicescript
    jacdac-stm32
)

stm32_print_size_of_target(devsrunner)
