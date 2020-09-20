//
// Created by Darwin Yuan on 2020/9/20.
//

#ifndef THEP_THREAD_SAFE_SIMPLE_LIST_H
#define THEP_THREAD_SAFE_SIMPLE_LIST_H

#include <thep/job_queue/simple_list.h>
#include <thep/util/spinlock.h>
#include <atomic>

THEP_NS_BEGIN

struct thread_safe_simple_list : private simple_list {
   template<typename T>
   auto dequeue() noexcept -> T* {
      auto elem = pop_front();
      if(elem == nullptr) return nullptr;
      return elem->to_value<T>();
   }

   auto enqueue(list_element* ptr) noexcept -> void {
      spinlock lock(lock_);
      simple_list::enqueue(ptr);
   }

   auto reschedule(list_element* ptr) noexcept -> bool {
      spinlock lock(lock_);
      if(simple_list::empty()) return false;
      simple_list::enqueue(ptr);
      return true;
   }

   auto empty() const noexcept -> bool {
      spinlock lock(lock_);
      return simple_list::empty();
   }

private:
   auto pop_front() noexcept -> list_element* {
      spinlock lock(lock_);
      return simple_list::pop_front();
   }

private:
   mutable std::atomic_flag lock_;
};

THEP_NS_END

#endif //THEP_THREAD_SAFE_SIMPLE_LIST_H
