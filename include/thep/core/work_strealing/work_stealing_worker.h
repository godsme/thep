//
// Created by Darwin Yuan on 2020/9/19.
//

#ifndef THEP_WORK_STEALING_WORKER_H
#define THEP_WORK_STEALING_WORKER_H

#include <thep/thep_ns.h>
#include <cstddef>
#include <thread>

THEP_NS_BEGIN

struct job;
struct work_stealing_pool;

using worker_id = std::size_t;

struct work_stealing_worker {
   using pool = work_stealing_pool;

   work_stealing_worker(worker_id id, pool& p) noexcept;
   auto id() const noexcept -> worker_id { return id_; }

   auto launch() noexcept -> void;
   auto join() noexcept -> void;

   auto sched_job(job *job) noexcept -> void;
   auto steal_job() noexcept -> job*;

private:
   std::thread thread_;
   worker_id id_;
   pool& pool_;
};

THEP_NS_END

#endif //THEP_WORK_STEALING_WORKER_H
