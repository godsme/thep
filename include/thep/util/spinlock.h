//
// Created by Darwin Yuan on 2020/9/20.
//

#ifndef THEP_SPINLOCK_H
#define THEP_SPINLOCK_H

#include <thep/thep_ns.h>
#include <atomic>
#include <thread>

THEP_NS_BEGIN

struct spinlock {
   spinlock(std::atomic_flag& lock) noexcept : lock_{lock} {
      while(lock.test_and_set(std::memory_order_acquire)) {
         std::this_thread::yield();
      }
   }

   ~spinlock() noexcept { lock_.clear(std::memory_order_release); }

private:
   std::atomic_flag& lock_;
};

THEP_NS_END

#endif //THEP_SPINLOCK_H
