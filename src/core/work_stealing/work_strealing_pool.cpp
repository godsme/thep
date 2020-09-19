//
// Created by Darwin Yuan on 2020/9/19.
//

#include <thep/core/work_strealing/work_stealing_pool.h>
#include <cstddef>

THEP_NS_BEGIN

work_stealing_pool::work_stealing_pool(std::size_t num_of_workers) noexcept
   : num_of_workers_{num_of_workers} {
}

auto work_stealing_pool::schedule_job(job&) noexcept -> void {
}

auto work_stealing_pool::shutdown() noexcept -> void {
}

work_stealing_pool::~work_stealing_pool() noexcept {
}

THEP_NS_END