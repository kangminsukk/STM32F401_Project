################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SPC582B_Stepmotor/components/spc582bxx_board_initialization_component_rla/cfg/board.c 

OBJS += \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_board_initialization_component_rla/cfg/board.o 

C_DEPS += \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_board_initialization_component_rla/cfg/board.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SPC582B_Stepmotor/components/spc582bxx_board_initialization_component_rla/cfg/%.o: ../Core/Src/SPC582B_Stepmotor/components/spc582bxx_board_initialization_component_rla/cfg/%.c Core/Src/SPC582B_Stepmotor/components/spc582bxx_board_initialization_component_rla/cfg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_board_initialization_component_rla-2f-cfg

clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_board_initialization_component_rla-2f-cfg:
	-$(RM) ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_board_initialization_component_rla/cfg/board.d ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_board_initialization_component_rla/cfg/board.o

.PHONY: clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_board_initialization_component_rla-2f-cfg

