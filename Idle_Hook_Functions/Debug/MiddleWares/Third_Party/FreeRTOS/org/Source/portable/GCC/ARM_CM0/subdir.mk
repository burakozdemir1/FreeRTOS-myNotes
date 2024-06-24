################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/port.c 

OBJS += \
./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/port.o 

C_DEPS += \
./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/port.d 


# Each subdirectory must supply rules for building sources it contributes
MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/%.o MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/%.su MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/%.cyclo: ../MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/%.c MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I"C:/denemeler/Idle_Hook_Functions/FreeRtosConfig" -I"C:/denemeler/Idle_Hook_Functions/MiddleWares/Third_Party/FreeRTOS/org/Source/include" -I"C:/denemeler/Idle_Hook_Functions/MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0" -I"C:/denemeler/Idle_Hook_Functions/MiddleWares/Third_Party/FreeRTOS/org/Source/portable/MemMang" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0

clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0:
	-$(RM) ./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/port.cyclo ./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/port.d ./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/port.o ./MiddleWares/Third_Party/FreeRTOS/org/Source/portable/GCC/ARM_CM0/port.su

.PHONY: clean-MiddleWares-2f-Third_Party-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-GCC-2f-ARM_CM0

