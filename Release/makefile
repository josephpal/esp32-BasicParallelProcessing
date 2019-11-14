################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries/Wire/src/subdir.mk
-include libraries/WiFi/src/subdir.mk
-include libraries/SX1509_IO_Expander/src/subdir.mk
-include libraries/SPIFFS/src/subdir.mk
-include libraries/SPI/src/subdir.mk
-include libraries/FS/src/subdir.mk
-include libraries/Adafruit_SSD1306/subdir.mk
-include libraries/Adafruit_GFX_Library/subdir.mk
-include core/core/libb64/subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/joseph/workspace/eclipse-ide/esp32-BasicMathExample/Release/arduino.ar \

ELF += \
esp32-BasicMathExample.elf \

HEX += \
esp32-BasicMathExample.hex \


# All Target
all: esp32-BasicMathExample

# Tool invocations
esp32-BasicMathExample: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/joseph/Arduino/hardware/espressif/esp32/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-size" -A "/home/joseph/workspace/eclipse-ide/esp32-BasicMathExample/Release/esp32-BasicMathExample.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/joseph/workspace/eclipse-ide/esp32-BasicMathExample/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/joseph/Arduino/hardware/espressif/esp32/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-ar" cru     /home/joseph/workspace/eclipse-ide/esp32-BasicMathExample/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

esp32-BasicMathExample.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/joseph/Arduino/hardware/espressif/esp32/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc" -nostdlib "-L/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/lib" "-L/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/ld" -T esp32_out.ld -T esp32.common.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.spiram_incompatible_fns.ld -u ld_include_panic_highint_hdl -u call_user_start_cpu0 -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  -u __cxa_guard_dummy -u __cxx_fatal_exception  -Wl,--start-group   $(LINK_OBJ)   /home/joseph/workspace/eclipse-ide/esp32-BasicMathExample/Release/arduino.ar  -lgcc -lopenssl -lbtdm_app -lfatfs -lwps -lcoexist -lwear_levelling -lesp_http_client -lprotobuf-c -lhal -lnewlib -ldriver -lbootloader_support -lpp -lfreemodbus -lmesh -lsmartconfig -ljsmn -lwpa -lethernet -lphy -lfrmn -lapp_trace -lfr_coefficients -lconsole -lulp -lwpa_supplicant -lfreertos -lbt -lmicro-ecc -lesp32-camera -lcxx -lxtensa-debug-module -ltcp_transport -lmdns -lvfs -lmtmn -lesp_ringbuf -lsoc -lcore -lfb_gfx -lsdmmc -llibsodium -lcoap -ltcpip_adapter -lprotocomm -lesp_event -limage_util -lc_nano -lesp-tls -lasio -lrtc -lspi_flash -lwpa2 -lwifi_provisioning -lesp32 -lface_recognition -lapp_update -lnghttp -lspiffs -lface_detection -lunity -lesp_https_server -lespnow -lnvs_flash -lesp_adc_cal -llog -ldl_lib -lsmartconfig_ack -lexpat -lfd_coefficients -lm -lmqtt -lc -lheap -lmbedtls -llwip -lnet80211 -lesp_http_server -lpthread -ljson -lesp_https_ota  -lstdc++ -Wl,--end-group -Wl,-EL -o "/home/joseph/workspace/eclipse-ide/esp32-BasicMathExample/Release/esp32-BasicMathExample.elf"
	@echo 'Finished building: $@'
	@echo ' '

esp32-BasicMathExample.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
