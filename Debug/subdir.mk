################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../arg_treatment.c \
../grep.c \
../read_file.c \
../search.c 

OBJS += \
./arg_treatment.o \
./grep.o \
./read_file.o \
./search.o 

C_DEPS += \
./arg_treatment.d \
./grep.d \
./read_file.d \
./search.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


