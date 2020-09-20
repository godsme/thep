//
// Created by Darwin Yuan on 2020/9/19.
//

#ifndef THEP_WORK_STEALING_POOL_H
#define THEP_WORK_STEALING_POOL_H

#include <thep/core/worker_id.h>
#include <cstddef>
#include <vector>

THEP_NS_BEGIN

struct resumable;
struct work_stealing_worker;

struct work_stealing_pool {
   explicit work_stealing_pool(std::size_t num_of_workers) noexcept;

   auto schedule_job(resumable&) noexcept -> void;
   auto shutdown() noexcept -> void;

   ~work_stealing_pool() noexcept;

private:
   auto launch_workers() noexcept -> void;

private:
   auto shutdown_notified() const noexcept -> bool;
   auto try_steal(worker_id) noexcept -> resumable*;

private:
   friend struct work_stealing_worker;
   std::vector<work_stealing_worker*> workers_;
   std::size_t num_of_workers_;
};

THEP_NS_END

#endif //THEP_WORK_STEALING_POOL_H
