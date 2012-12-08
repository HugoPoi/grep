################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../arg_treatment.c \
../fct_grep.c \
../grep.c \
../read_file.c \
../run_through_dir.c \
../search.c 

OBJS += \
./arg_treatment.o \
./fct_grep.o \
./grep.o \
./read_file.o \
./run_through_dir.o \
./search.o 

C_DEPS += \
./arg_treatment.d \
./fct_grep.d \
./grep.d \
./read_file.d \
./run_through_dir.d \
./search.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


