################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EEPROM_program.c \
../HKPD_program.c \
../HLCD_program.c \
../M-adc_program.c \
../MDIO_program.c \
../MTWI_program.c \
../MUART_Driver_iti_program.c \
../SPI_program.c \
../main.c 

OBJS += \
./EEPROM_program.o \
./HKPD_program.o \
./HLCD_program.o \
./M-adc_program.o \
./MDIO_program.o \
./MTWI_program.o \
./MUART_Driver_iti_program.o \
./SPI_program.o \
./main.o 

C_DEPS += \
./EEPROM_program.d \
./HKPD_program.d \
./HLCD_program.d \
./M-adc_program.d \
./MDIO_program.d \
./MTWI_program.d \
./MUART_Driver_iti_program.d \
./SPI_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


