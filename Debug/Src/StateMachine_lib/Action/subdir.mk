################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/StateMachine_lib/Action/Action.cpp 

OBJS += \
./Src/StateMachine_lib/Action/Action.o 

CPP_DEPS += \
./Src/StateMachine_lib/Action/Action.d 


# Each subdirectory must supply rules for building sources it contributes
Src/StateMachine_lib/Action/%.o: ../Src/StateMachine_lib/Action/%.cpp Src/StateMachine_lib/Action/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

