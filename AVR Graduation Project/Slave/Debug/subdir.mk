################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HLCD_Program.c \
../HSSD_program.c \
../ITI_KPD_program.c \
../MDIO_program.c \
../MEXI_program.c \
../MGIE_program.c \
../MSPI_program.c \
../MTIMER_program.c \
../SERVO_program.c \
../SPI_program.c \
../main.c 

OBJS += \
./HLCD_Program.o \
./HSSD_program.o \
./ITI_KPD_program.o \
./MDIO_program.o \
./MEXI_program.o \
./MGIE_program.o \
./MSPI_program.o \
./MTIMER_program.o \
./SERVO_program.o \
./SPI_program.o \
./main.o 

C_DEPS += \
./HLCD_Program.d \
./HSSD_program.d \
./ITI_KPD_program.d \
./MDIO_program.d \
./MEXI_program.d \
./MGIE_program.d \
./MSPI_program.d \
./MTIMER_program.d \
./SERVO_program.d \
./SPI_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


