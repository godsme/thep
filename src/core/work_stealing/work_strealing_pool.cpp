//
// Created by Darwin Yuan on 2020/9/19.
//

#include <thep/core/work_strealing/work_stealing_pool.h>
#include <thep/core/work_strealing/work_stealing_worker.h>
#include <cstddef>

THEP_NS_BEGIN

work_stealing_pool::work_stealing_pool(std::size_t num_of_workers) noexcept
   : num_of_workers_{num_of_workers} {
   launch_workers();
}

auto work_stealing_pool::schedule_job(job&) noexcept -> void {
}

auto work_stealing_pool::shutdown() noexcept -> void {
}

auto work_stealing_pool::launch_workers() noexcept -> void {
   workers_.reserve(num_of_workers_);

   for(std::size_t i=0; i<num_of_workers_; i++) {
      workers_.emplace_back(new work_stealing_worker{i, *this});
   }

   for(auto& worker : workers_) {
      worker->launch();
   }
}

work_stealing_pool::~work_stealing_pool() noexcept {
}


THEP_NS_END