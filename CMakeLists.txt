cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico)
pico_sdk_init()
add_executable(PicoMiteVGA
	PicoMite.c
	MMBasic.c
	Operators.c
	Custom.c
	Functions.c
	Commands.c
	Memory.c
	FileIO.c
	ff.c
	ffsystem.c
	ffunicode.c
	mmc_stm32.c
	Draw.c
	Editor.c
	XModem.c
	MM_Misc.c
	External.c
	MATHS.c
	Onewire.c
	I2C.c
	SPI.c
	Serial.c
	SPI-LCD.c
	BmpDecoder.c
	GPS.c
	Audio.c
	CFunction.c
	Keyboard.c
    picojpeg.c 
    lfs.c
    lfs_util.c
)
pico_define_boot_stage2(slower_boot2 ${PICO_DEFAULT_BOOT_STAGE2_FILE})
target_compile_definitions(slower_boot2 PRIVATE PICO_FLASH_SPI_CLKDIV=4)
pico_set_boot_stage2(PicoMiteVGA slower_boot2)
pico_generate_pio_header(PicoMiteVGA ${CMAKE_CURRENT_LIST_DIR}/PicoMiteVGA.pio)
Pico_enable_stdio_usb(PicoMiteVGA 1)
pico_enable_stdio_uart(PicoMiteVGA 0)
pico_add_extra_outputs(PicoMiteVGA)
target_compile_options(PicoMiteVGA PRIVATE -DPICOMITEVGA -DPICO_FLASH_SIZE_BYTES=16777216 -DPICO_STDIO_USB_ENABLE_RESET_VIA_VENDOR_INTERFACE=0 -DPICO_STACK_SIZE=0x1000 -DPICO_CORE1_STACK_SIZE=0x0 -DPICO_HEAP_SIZE=0x400)
target_link_libraries(PicoMiteVGA
	pico_stdlib
	hardware_flash
	hardware_irq
	hardware_adc
	hardware_pwm
	hardware_i2c
	hardware_spi
	hardware_dma
	hardware_exception
	pico_multicore
	hardware_pio
)
