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
Lab2_Hossam.lss \

FLASH_IMAGE += \
Lab2_Hossam.hex \

EEPROM_IMAGE += \
Lab2_Hossam.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Lab2_Hossam.elf secondary-outputs

# Tool invocations
Lab2_Hossam.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Lab2_Hossam.map -mmcu=atmega32 -o "Lab2_Hossam.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Lab2_Hossam.lss: Lab2_Hossam.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Lab2_Hossam.elf  >"Lab2_Hossam.lss"
	@echo 'Finished building: $@'
	@echo ' '

Lab2_Hossam.hex: Lab2_Hossam.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Lab2_Hossam.elf  "Lab2_Hossam.hex"
	@echo 'Finished building: $@'
	@echo ' '

Lab2_Hossam.eep: Lab2_Hossam.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Lab2_Hossam.elf  "Lab2_Hossam.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Lab2_Hossam.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Lab2_Hossam.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Lab2_Hossam.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
