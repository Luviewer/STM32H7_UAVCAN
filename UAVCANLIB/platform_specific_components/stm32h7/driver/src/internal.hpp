/*
 * Copyright (C) 2014 Pavel Kirienko <pavel.kirienko@gmail.com>
 */

#pragma once

#include <uavcan_stm32h7/build_config.hpp>

#include <chip.h> // See http://uavcan.org/Implementations/Libuavcan/Platforms/STM32/

/**
 * Debug output
 */
#define UAVCAN_STM32H7_LOG(...) ((void)0)


/**
 * IRQ handler macros
 */
#define UAVCAN_STM32H7_IRQ_HANDLER(id) void id(void)
#define UAVCAN_STM32H7_IRQ_PROLOGUE()
#define UAVCAN_STM32H7_IRQ_EPILOGUE()

#ifndef UAVCAN_STM32H7_IRQ_PRIORITY_MASK
    #define UAVCAN_STM32H7_IRQ_PRIORITY_MASK 0
#endif

/**
 * Glue macros
 */
#define UAVCAN_STM32H7_GLUE2_(A, B) A##B
#define UAVCAN_STM32H7_GLUE2(A, B)  UAVCAN_STM32H7_GLUE2_(A, B)

#define UAVCAN_STM32H7_GLUE3_(A, B, C) A##B##C
#define UAVCAN_STM32H7_GLUE3(A, B, C)  UAVCAN_STM32H7_GLUE3_(A, B, C)

namespace uavcan_stm32h7 {

struct CriticalSectionLocker {

    CriticalSectionLocker()
    {
        __disable_irq();
    }

    ~CriticalSectionLocker()
    {
        __enable_irq();
    }
};

namespace clock
{
uavcan::uint64_t getUtcUSecFromCanInterrupt();
}
}

