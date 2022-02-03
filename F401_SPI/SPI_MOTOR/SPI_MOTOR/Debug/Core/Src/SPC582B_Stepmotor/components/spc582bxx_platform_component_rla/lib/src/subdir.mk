################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/boot.s \
../Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/crt0.s 

OBJS += \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/boot.o \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/crt0.o 

S_DEPS += \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/boot.d \
./Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/crt0.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/%.o: ../Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/%.s Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_platform_component_rla-2f-lib-2f-src

clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_platform_component_rla-2f-lib-2f-src:
	-$(RM) ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/boot.d ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/boot.o ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/crt0.d ./Core/Src/SPC582B_Stepmotor/components/spc582bxx_platform_component_rla/lib/src/crt0.o

.PHONY: clean-Core-2f-Src-2f-SPC582B_Stepmotor-2f-components-2f-spc582bxx_platform_component_rla-2f-lib-2f-src

