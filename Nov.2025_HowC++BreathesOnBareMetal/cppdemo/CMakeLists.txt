cmake_minimum_required(VERSION 3.13)

# initialize the SDK directly
include(pico_sdk_import.cmake)

project(demo)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_definitions(-DPICO_DEFAULT_LED_PIN=25)
add_executable(demo
    demo.c
    )

# pull in common dependencies
target_link_libraries(demo pico_stdlib)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(demo pico_cyw43_arch_none)
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(demo)

# add url via pico_set_program_url
# example_auto_set_url(demo)
