//
// Created by Darwin Yuan on 2020/9/19.
//

#ifndef THEP_WORK_STEALING_WORKER_H
#define THEP_WORK_STEALING_WORKER_H

#include <thep/job_queue/thread_safe_simple_list.h>
#include <cstddef>
#include <thread>
#include <thep/core/worker_id.h>

THEP_NS_BEGIN

struct resumable;
struct work_stealing_pool;

struct work_stealing_worker {
   using pool = work_stealing_pool;

   work_stealing_worker(worker_id id, pool& p) noexcept;
   auto id() const noexcept -> worker_id { return id_; }

   auto launch() noexcept -> void;
   auto join() noexcept -> void;

   auto sched_job(resumable *job) noexcept -> void;
   auto take_a_job() noexcept -> resumable*;

private:
   auto run() -> void;
   auto get_a_job() noexcept -> resumable*;
   auto resume_job(resumable* job) noexcept -> void;
   auto resume_once(resumable* job) noexcept -> bool;

private:
   thread_safe_simple_list job_queue_{};
   std::thread thread_;
   worker_id id_;
   pool& pool_;
};

THEP_NS_END

#endif //THEP_WORK_STEALING_WORKER_H
