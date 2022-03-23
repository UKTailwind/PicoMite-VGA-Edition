// ****************************************************************************
//
//                                 Main code
//
// ****************************************************************************
#ifndef _INCLUDE_H
#define _INCLUDE_H



typedef unsigned char Bool;
#define True 1
#define False 0

// NULL
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif

// I/O port prefix
#define __IO	volatile

// request to use inline
#define INLINE __attribute__((always_inline)) inline

// avoid to use inline
#define NOINLINE __attribute__((noinline))

// weak function
#define WEAK __attribute__((weak))

// align array to 4-bytes
#define ALIGNED __attribute__((aligned(4)))

// default LED pin
#define LED_PIN 25

// nop instruction
INLINE void nop()
	{ __asm volatile (" nop\n"); }

// compiler barrier
INLINE void cb()
	{ __asm volatile ("" ::: "memory"); }

// ----------------------------------------------------------------------------
//                               Constants
// ----------------------------------------------------------------------------


#define BIT(pos) (1UL<<(pos))


// ----------------------------------------------------------------------------
//                                   Includes
// ----------------------------------------------------------------------------

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <string.h>
#include "hardware/divider.h"
#include "hardware/dma.h"
#include "hardware/irq.h"

#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "configuration.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
#include "hardware/flash.h"
#include "hardware/adc.h"
#include "hardware/exception.h"
#include "hardware/structs/systick.h"
#include "hardware/structs/scb.h"
#include "hardware/vreg.h"
#include "pico/unique_id.h"
#include <pico/bootrom.h>
#include "hardware/irq.h"
#include "hardware/pio.h"
#include "PicoMiteVGA.pio.h"
#include "class/cdc/cdc_device.h" 


// ****************************************************************************
//
//                                    QVGA configuration
//
// ****************************************************************************
// port pins
//	GP22... VGA
//	GP16 ... VGA HSYNC/CSYNC synchronization (inverted: negative SYNC=LOW=0x80, BLACK=HIGH=0x00)
//	GP17 ... VSYNC

// QVGA port pins
#define QVGA_GPIO_FIRST	18	// first QVGA GPIO
#define QVGA_GPIO_NUM	4	// number of QVGA color GPIOs, without HSYNC and VSYNC
#define QVGA_GPIO_LAST	(QVGA_GPIO_FIRST+QVGA_GPIO_NUM-1) // last QVGA GPIO
#define QVGA_GPIO_HSYNC	16	// QVGA HSYNC/CSYNC GPIO
#define QVGA_GPIO_VSYNC	(QVGA_GPIO_HSYNC+1) // QVGA VSYNC GPIO

// QVGA PIO and state machines
#define QVGA_PIO	pio0	// QVGA PIO
#define QVGA_SM		0	// QVGA state machine

// QVGA DMA channel
#define QVGA_DMA_CB	0	// DMA control block of base layer
#define QVGA_DMA_PIO	1	// DMA copy data to PIO (raises IRQ0 on quiet)

// QVGA display resolution
#define FRAMESIZE (38400) // display frame size in bytes (=38400)

// 126 MHz timings
//#define QVGA_TOTAL	(DISPLAY_TYPE==COLOURVGA ? 2002	: 4004)// total clock ticks (= QVGA_HSYNC + QVGA_BP + WIDTH*QVGA_CPP[1600] + QVGA_FP)
//#define QVGA_HSYNC	(DISPLAY_TYPE==COLOURVGA ?  240	: 480)	// horizontal sync clock ticks
//#define QVGA_BP	(DISPLAY_TYPE==COLOURVGA ?  121	: 242)	// back porch clock ticks
//#define QVGA_FP	(DISPLAY_TYPE==COLOURVGA ?  41	: 82)	// front porch clock ticks
#define QVGA_TOTAL	4004// total clock ticks (= QVGA_HSYNC + QVGA_BP + WIDTH*QVGA_CPP[1600] + QVGA_FP)
#define QVGA_HSYNC	480	// horizontal sync clock ticks
#define QVGA_BP	 242	// back porch clock ticks
#define QVGA_FP	82	// front porch clock ticks

// QVGA vertical timings
#define QVGA_VTOT	525	// total scanlines (= QVGA_VSYNC + QVGA_VBACK + QVGA_VACT + QVGA_VFRONT)
#define QVGA_VSYNC	2	// length of V sync (number of scanlines)
#define QVGA_VBACK	33	// V back porch
#define QVGA_VACT	480	// V active scanlines (= 2*HEIGHT)
#define QVGA_VFRONT	10	// V front porch

#endif // _MAIN_H
