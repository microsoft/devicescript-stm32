file(GLOB RUNNER_FILES *.c)

add_executable(devsrunner
    ${RUNNER_FILES}
    ${CMAKE_BINARY_DIR}/version.c
)

include_directories(AFTER
    "."
)

target_link_libraries(devsrunner CMSIS::STM32::${MCU} STM32::NoSys)
stm32_print_size_of_target(devsrunner)
