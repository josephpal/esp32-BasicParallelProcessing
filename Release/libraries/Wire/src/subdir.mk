################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/joseph/Arduino/hardware/espressif/esp32/libraries/Wire/src/Wire.cpp 

LINK_OBJ += \
./libraries/Wire/src/Wire.cpp.o 

CPP_DEPS += \
./libraries/Wire/src/Wire.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Wire/src/Wire.cpp.o: /home/joseph/Arduino/hardware/espressif/esp32/libraries/Wire/src/Wire.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/joseph/Arduino/hardware/espressif/esp32/tools/xtensa-esp32-elf/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM -DMBEDTLS_CONFIG_FILE="mbedtls/esp_config.h" -DHAVE_CONFIG_H "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/config" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/app_trace" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/app_update" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/asio" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/bootloader_support" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/bt" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/coap" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/console" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/driver" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp-tls" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp32" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp_adc_cal" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp_event" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp_http_client" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp_http_server" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp_https_ota" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp_https_server" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp_ringbuf" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/ethernet" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/expat" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/fatfs" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/freemodbus" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/freertos" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/heap" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/idf_test" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/jsmn" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/json" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/libsodium" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/log" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/lwip" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/mbedtls" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/mdns" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/micro-ecc" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/mqtt" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/newlib" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/nghttp" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/nvs_flash" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/openssl" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/protobuf-c" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/protocomm" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/pthread" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/sdmmc" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/smartconfig_ack" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/soc" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/spi_flash" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/spiffs" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/tcp_transport" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/tcpip_adapter" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/ulp" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/unity" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/vfs" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/wear_levelling" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/wifi_provisioning" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/wpa_supplicant" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/xtensa-debug-module" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp32-camera" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/esp-face" "-I/home/joseph/Arduino/hardware/espressif/esp32/tools/sdk/include/fb_gfx" -std=gnu++11 -fno-exceptions -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wall -Werror=all -Wextra -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=240000000L -DARDUINO=10802 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 -DARDUINO_BOARD="ESP32_DEV" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=0    -I"/home/joseph/Arduino/hardware/espressif/esp32/cores/esp32" -I"/home/joseph/Arduino/hardware/espressif/esp32/variants/esp32" -I"/home/joseph/Arduino/libraries/Adafruit_GFX_Library" -I"/home/joseph/Arduino/libraries/Adafruit_SSD1306" -I"/home/joseph/Arduino/hardware/espressif/esp32/libraries/FS/src" -I"/home/joseph/Arduino/hardware/espressif/esp32/libraries/SPI/src" -I"/home/joseph/Arduino/hardware/espressif/esp32/libraries/SPIFFS/src" -I"/home/joseph/Arduino/libraries/SX1509_IO_Expander/src" -I"/home/joseph/Arduino/hardware/espressif/esp32/libraries/WiFi/src" -I"/home/joseph/Arduino/hardware/espressif/esp32/libraries/Wire/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


