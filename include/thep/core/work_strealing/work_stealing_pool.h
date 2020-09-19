//
// Created by Darwin Yuan on 2020/9/19.
//

#ifndef THEP_WORK_STEALING_POOL_H
#define THEP_WORK_STEALING_POOL_H

#include <thep/thep_ns.h>
#include <cstddef>
#include <vector>

THEP_NS_BEGIN

struct job;
struct work_stealing_worker;

struct work_stealing_pool {
   explicit work_stealing_pool(std::size_t num_of_workers) noexcept;

   auto schedule_job(job&) noexcept -> void;
   auto shutdown() noexcept -> void;

   ~work_stealing_pool() noexcept;

private:
   friend work_stealing_worker;
   std::vector<work_stealing_worker*> workers_;
   std::size_t num_of_workers_;
};

THEP_NS_END

#endif //THEP_WORK_STEALING_POOL_H
