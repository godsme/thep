//
// Created by Darwin Yuan on 2020/9/19.
//

#ifndef THEP_RESUMABLE_H
#define THEP_RESUMABLE_H

#include <thep/job_queue/simple_list_element.h>
#include <cstddef>
#include <limits>

THEP_NS_BEGIN

struct resumable : simple_list_element {
   virtual auto resume() noexcept -> bool = 0;
   virtual ~resumable() = 0;

   virtual auto add_ref() noexcept -> void {}
   virtual auto release() noexcept -> void { delete this; }

   auto set_last_served_worker(size_t worker_id) -> void { served_worker_ = worker_id; }
   auto last_served_worker() -> size_t { return served_worker_; }

private:
   std::size_t served_worker_{std::numeric_limits<std::size_t>::max()};
};

THEP_NS_END

#endif //THEP_RESUMABLE_H
