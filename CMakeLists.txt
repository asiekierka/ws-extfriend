# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/usr/share/pico-sdk")

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "2.0.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 2.0.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(extfriend C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(extfriend
  headphone.c
  info.c
  main.c
  uart.c
  usb.c
  usb_descriptors.c
)

pico_generate_pio_header(extfriend ${CMAKE_CURRENT_LIST_DIR}/headphone_pio.pio)

pico_set_program_name(extfriend "ExtFriend for WS")
pico_set_program_version(extfriend "0.1")

pico_set_binary_type(extfriend copy_to_ram)

pico_enable_stdio_uart(extfriend 1)
pico_enable_stdio_usb(extfriend 0)

# Add the standard library to the build
target_link_libraries(extfriend
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(extfriend PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(extfriend
        hardware_dma
        hardware_pio
	pico_multicore
        tinyusb_device tinyusb_board
        )

pico_add_extra_outputs(extfriend)

