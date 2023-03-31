cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/arm-none-eabi-gcc.cmake)

string(SUBSTRING ${MCU} 0 2 FAMILY)
string(SUBSTRING ${MCU} 0 4 MCU_NUM)
string(TOLOWER ${MCU_NUM} MCU_NUM_LOWER)
set(STM32_CUBE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/STM32Cube${FAMILY})

project(devicescript_stm32 C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_BUILD_TYPE Debug)

set(ARCH_FLAGS
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -mthumb
    -nostartfiles
    -g3
)

add_compile_options(
    -Wall
    -Wextra
    -Wstrict-prototypes

    -Wno-unused-parameter
    -Wno-shift-negative-value
    -Wno-zero-length-bounds
    -Wno-strict-aliasing

    -ffunction-sections
    ${ARCH_FLAGS}

    -DSTM32${FAMILY}=1
    -DSTM32${MCU_NUM}xx=1
    -Os
)

include(${CMAKE_BINARY_DIR}/config.cmake)

add_subdirectory(src)

# location of jd_user_config.h
set(JACDAC_USER_CONFIG_DIR "../../../src")
add_subdirectory(devicescript/runtime/jacdac-c)
add_subdirectory(devicescript/runtime/devicescript)
add_subdirectory(jacdac-stm32x0)
