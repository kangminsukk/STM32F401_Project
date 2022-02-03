################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/vectors.s 

C_SRCS += \
../Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/eirq.c \
../Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/irq.c \
../Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/swirq.c 

OBJS += \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/eirq.o \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/irq.o \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/swirq.o \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/vectors.o 

S_DEPS += \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/vectors.d 

C_DEPS += \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/eirq.d \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/irq.d \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/swirq.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/%.o: ../Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/%.c Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/%.o: ../Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/%.s Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_irq_component_rla-2f-lib-2f-src

clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_irq_component_rla-2f-lib-2f-src:
	-$(RM) ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/eirq.d ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/eirq.o ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/irq.d ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/irq.o ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/swirq.d ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/swirq.o ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/vectors.d ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_irq_component_rla/lib/src/vectors.o

.PHONY: clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_irq_component_rla-2f-lib-2f-src

