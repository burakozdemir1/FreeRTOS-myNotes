################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/heap_4.c 

OBJS += \
./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/%.o MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/%.su MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/%.cyclo: ../MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/%.c MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I"C:/denemeler/Semaphore_Two_Tasks/MiddleWares/Third_Party/FreeRTOS/org/Source/include" -I"C:/denemeler/Semaphore_Two_Tasks/MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0" -I"C:/denemeler/Semaphore_Two_Tasks/MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang" -I../Core/Inc -I"C:/denemeler/Semaphore_Two_Tasks/FreeRtosConfig" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-MemMang

clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/heap_4.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/heap_4.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/heap_4.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang/heap_4.su

.PHONY: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-MemMang

