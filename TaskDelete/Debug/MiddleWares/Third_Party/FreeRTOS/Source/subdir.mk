################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MiddleWares/Third_Party/FreeRTOS/Source/croutine.c \
../MiddleWares/Third_Party/FreeRTOS/Source/event_groups.c \
../MiddleWares/Third_Party/FreeRTOS/Source/list.c \
../MiddleWares/Third_Party/FreeRTOS/Source/queue.c \
../MiddleWares/Third_Party/FreeRTOS/Source/stream_buffer.c \
../MiddleWares/Third_Party/FreeRTOS/Source/tasks.c \
../MiddleWares/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./MiddleWares/Third_Party/FreeRTOS/Source/croutine.o \
./MiddleWares/Third_Party/FreeRTOS/Source/event_groups.o \
./MiddleWares/Third_Party/FreeRTOS/Source/list.o \
./MiddleWares/Third_Party/FreeRTOS/Source/queue.o \
./MiddleWares/Third_Party/FreeRTOS/Source/stream_buffer.o \
./MiddleWares/Third_Party/FreeRTOS/Source/tasks.o \
./MiddleWares/Third_Party/FreeRTOS/Source/timers.o 

C_DEPS += \
./MiddleWares/Third_Party/FreeRTOS/Source/croutine.d \
./MiddleWares/Third_Party/FreeRTOS/Source/event_groups.d \
./MiddleWares/Third_Party/FreeRTOS/Source/list.d \
./MiddleWares/Third_Party/FreeRTOS/Source/queue.d \
./MiddleWares/Third_Party/FreeRTOS/Source/stream_buffer.d \
./MiddleWares/Third_Party/FreeRTOS/Source/tasks.d \
./MiddleWares/Third_Party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
MiddleWares/Third_Party/FreeRTOS/Source/%.o MiddleWares/Third_Party/FreeRTOS/Source/%.su MiddleWares/Third_Party/FreeRTOS/Source/%.cyclo: ../MiddleWares/Third_Party/FreeRTOS/Source/%.c MiddleWares/Third_Party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I"C:/denemeler/TaskDelete/FreeRtosConfig" -I"C:/denemeler/TaskDelete/MiddleWares/Third_Party/FreeRTOS/org/Source/include" -I"C:/denemeler/TaskDelete/MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0" -I"C:/denemeler/TaskDelete/MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-Source

clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-Source:
	-$(RM) ./MiddleWares/Third_Party/FreeRTOS/Source/croutine.cyclo ./MiddleWares/Third_Party/FreeRTOS/Source/croutine.d ./MiddleWares/Third_Party/FreeRTOS/Source/croutine.o ./MiddleWares/Third_Party/FreeRTOS/Source/croutine.su ./MiddleWares/Third_Party/FreeRTOS/Source/event_groups.cyclo ./MiddleWares/Third_Party/FreeRTOS/Source/event_groups.d ./MiddleWares/Third_Party/FreeRTOS/Source/event_groups.o ./MiddleWares/Third_Party/FreeRTOS/Source/event_groups.su ./MiddleWares/Third_Party/FreeRTOS/Source/list.cyclo ./MiddleWares/Third_Party/FreeRTOS/Source/list.d ./MiddleWares/Third_Party/FreeRTOS/Source/list.o ./MiddleWares/Third_Party/FreeRTOS/Source/list.su ./MiddleWares/Third_Party/FreeRTOS/Source/queue.cyclo ./MiddleWares/Third_Party/FreeRTOS/Source/queue.d ./MiddleWares/Third_Party/FreeRTOS/Source/queue.o ./MiddleWares/Third_Party/FreeRTOS/Source/queue.su ./MiddleWares/Third_Party/FreeRTOS/Source/stream_buffer.cyclo ./MiddleWares/Third_Party/FreeRTOS/Source/stream_buffer.d ./MiddleWares/Third_Party/FreeRTOS/Source/stream_buffer.o ./MiddleWares/Third_Party/FreeRTOS/Source/stream_buffer.su ./MiddleWares/Third_Party/FreeRTOS/Source/tasks.cyclo ./MiddleWares/Third_Party/FreeRTOS/Source/tasks.d ./MiddleWares/Third_Party/FreeRTOS/Source/tasks.o ./MiddleWares/Third_Party/FreeRTOS/Source/tasks.su ./MiddleWares/Third_Party/FreeRTOS/Source/timers.cyclo ./MiddleWares/Third_Party/FreeRTOS/Source/timers.d ./MiddleWares/Third_Party/FreeRTOS/Source/timers.o ./MiddleWares/Third_Party/FreeRTOS/Source/timers.su

.PHONY: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-Source

