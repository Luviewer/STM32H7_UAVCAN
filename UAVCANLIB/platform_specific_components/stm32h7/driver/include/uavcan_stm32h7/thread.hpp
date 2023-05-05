/*
 * Copyright (C) 2014 Pavel Kirienko <pavel.kirienko@gmail.com>
 */

#pragma once

#include <uavcan_stm32h7/build_config.hpp>

#include <uavcan/uavcan.hpp>

namespace uavcan_stm32h7 {

class CanDriver;

class BusEvent {
    volatile bool ready;

public:
    BusEvent(CanDriver& can_driver)
        : ready(false)
    {
        (void)can_driver;
    }

    bool wait(uavcan::MonotonicDuration duration)
    {
        (void)duration;
        bool lready = ready;
#if defined(__CC_ARM)
        return __sync_lock_test_and_set(&lready, false);
#elif defined(__GNUC__)
        return __atomic_exchange_n(&lready, false, __ATOMIC_SEQ_CST);
#else
    #error "This compiler is not supported"
#endif
    }

    void signal()
    {
#if defined(__CC_ARM)
        __sync_lock_release(&ready);
#elif defined(__GNUC__)
        __atomic_store_n(&ready, true, __ATOMIC_SEQ_CST);
#else
    #error "This compiler is not supported"
#endif
    }

    void signalFromInterrupt()
    {
#if defined(__CC_ARM)
        __sync_lock_release(&ready);
#elif defined(__GNUC__)
        __atomic_store_n(&ready, true, __ATOMIC_SEQ_CST);
#else
    #error "This compiler is not supported"
#endif
    }
};

class Mutex {
public:
    void lock() { }
    void unlock() { }
};

class MutexLocker {
    Mutex& mutex_;

public:
    MutexLocker(Mutex& mutex)
        : mutex_(mutex)
    {
        mutex_.lock();
    }
    ~MutexLocker()
    {
        mutex_.unlock();
    }
};

}
