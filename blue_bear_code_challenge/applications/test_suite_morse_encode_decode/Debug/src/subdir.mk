################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test_suite_morse_encode_decode.cpp 

OBJS += \
./src/test_suite_morse_encode_decode.o 

CPP_DEPS += \
./src/test_suite_morse_encode_decode.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"/home/sundev/sundev_code/blue_bear_code_challenge/common_types" -I"/home/sundev/sundev_code/blue_bear_code_challenge/file_encode_decode/src" -I"/home/sundev/sundev_code/blue_bear_code_challenge/encode_decode_algorithms/src" -I"/home/sundev/sundev_code/blue_bear_code_challenge/utilities/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


