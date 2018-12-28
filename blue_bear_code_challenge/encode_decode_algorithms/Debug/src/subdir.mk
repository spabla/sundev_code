################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/morse_to_text_algorithm.cpp \
../src/text_to_morse_algorithm.cpp 

OBJS += \
./src/morse_to_text_algorithm.o \
./src/text_to_morse_algorithm.o 

CPP_DEPS += \
./src/morse_to_text_algorithm.d \
./src/text_to_morse_algorithm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"/home/sundev/sundev_code/blue_bear_code_challenge/utilities/src" -I"/home/sundev/sundev_code/blue_bear_code_challenge/common_types" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


