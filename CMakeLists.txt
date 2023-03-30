cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/stm32-cmake/cmake/stm32_gcc.cmake)
set(STM32_CUBE_L4_PATH ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeL4)

project(devicescript_stm32 C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_BUILD_TYPE Debug)

find_package(CMSIS COMPONENTS STM32${MCU} REQUIRED)

add_compile_options(-Wall
    -Wno-format
    -Wno-unused-function
    -Wno-maybe-uninitialized
    -Wno-zero-length-bounds
    -ffunction-sections
)

include(${CMAKE_BINARY_DIR}/config.cmake)

add_subdirectory(src)

# location of jd_user_config.h
set(JACDAC_USER_CONFIG_DIR "../../../src")
add_subdirectory(devicescript/runtime/jacdac-c)
add_subdirectory(devicescript/runtime/devicescript)
