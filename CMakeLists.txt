cmake_minimum_required(VERSION 3.7)
project(l4_windsensor C ASM)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DSTM32L432xx -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DUNALIGNED_SUPPORT_DISABLE -DUSE_HAL -D__FPU_PRESENT=1 )

file(GLOB_RECURSE USER_SOURCES "Src/*.c" "Inc/*.h")
file(GLOB_RECURSE STD_SOURCES
        "Drivers/**/*.h"
        "Drivers/**/*.c"
        "startup/*.s"
        "DSP_Lib/Source/BasicMathFunctions/arm_offset_q15.c"
        "DSP_Lib/Source/SupportFunctions/*_q15.c"
        "DSP_Lib/Source/StatisticsFunctions/arm_max_q15.c"
        "DSP_Lib/Source/StatisticsFunctions/arm_min_q15.c"
        "DSP_Lib/Source/StatisticsFunctions/arm_mean_q15.c"
        "DSP_Lib/Source/FilteringFunctions/arm_correlate_fast_q15.c"
        "DSP_Lib/Source/FilteringFunctions/arm_conv_fast_q15.c"
        "DSP_Lib/Source/FilteringFunctions/arm_conv_partial_fast_q15.c"
        )
#file(GLOB_RECURSE DSP_SOURCES "Drivers/CMSIS/DSP_Lib/Source/*/*.c")

include_directories(Inc Drivers/STM32L4xx_HAL_Driver/Inc)
include_directories(Drivers/CMSIS/Include)
include_directories(Drivers/CMSIS/DSP_Lib/Include)
include_directories(Drivers/CMSIS/Device/ST/STM32L4xx/Include)
include_directories(SVD_Inc)

add_executable(${PROJECT_NAME}.elf ${USER_SOURCES} ${STD_SOURCES} STM32L432KCUx_FLASH.cmake STM32L432KCUx_FLASH.ld)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map")

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} \nBuilding ${BIN_FILE}")

add_custom_target(UPLOAD
        arm-none-eabi-gdb -iex "target remote tcp:127.0.0.1:3333"
        -iex "monitor program $<TARGET_FILE:${PROJECT_NAME}.elf>"
        -iex "monitor reset init"
        -iex "disconnect" -iex "quit")

