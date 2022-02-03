################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SPC582B_Stepmotor/main.c 

OBJS += \
./Core/Src/SPC582B_Stepmotor/main.o 

C_DEPS += \
./Core/Src/SPC582B_Stepmotor/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SPC582B_Stepmotor/%.o: ../Core/Src/SPC582B_Stepmotor/%.c Core/Src/SPC582B_Stepmotor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-SPC582B_Stepmotor

clean-Core-2f-Src-2f-SPC582B_Stepmotor:
	-$(RM) ./Core/Src/SPC582B_Stepmotor/main.d ./Core/Src/SPC582B_Stepmotor/main.o

.PHONY: clean-Core-2f-Src-2f-SPC582B_Stepmotor

