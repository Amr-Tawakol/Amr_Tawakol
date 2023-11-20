################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Simple_Solar_Tracking.lss \

FLASH_IMAGE += \
Simple_Solar_Tracking.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Simple_Solar_Tracking.elf secondary-outputs

# Tool invocations
Simple_Solar_Tracking.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Simple_Solar_Tracking.map -mmcu=atmega32 -o "Simple_Solar_Tracking.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Simple_Solar_Tracking.lss: Simple_Solar_Tracking.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Simple_Solar_Tracking.elf  >"Simple_Solar_Tracking.lss"
	@echo 'Finished building: $@'
	@echo ' '

Simple_Solar_Tracking.hex: Simple_Solar_Tracking.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Simple_Solar_Tracking.elf  "Simple_Solar_Tracking.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Simple_Solar_Tracking.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Simple_Solar_Tracking.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Simple_Solar_Tracking.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
