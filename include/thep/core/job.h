//
// Created by Darwin Yuan on 2020/9/19.
//

#ifndef THEP_JOB_H
#define THEP_JOB_H

#include <thep/thep_ns.h>
#include <cstddef>
#include <limits>

THEP_NS_BEGIN

struct job {
   enum class result_t {
      exec_later,
      await,
      done,
      shutdown
   };

   virtual auto exec() noexcept -> result_t = 0;
   virtual ~job() = 0;

   virtual auto add_ref() noexcept -> void {}
   virtual auto release() noexcept -> void { delete this; }

   auto set_last_served_worker(size_t worker_id) -> void { served_worker_ = worker_id; }
   auto last_served_worker() -> size_t { return served_worker_; }

private:
   std::size_t served_worker_{std::numeric_limits<std::size_t>::max()};
};

THEP_NS_END

#endif //THEP_JOB_H
