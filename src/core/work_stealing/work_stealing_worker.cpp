//
// Created by Darwin Yuan on 2020/9/19.
//

#include <thep/core/work_strealing/work_stealing_worker.h>
#include <thep/core/work_strealing/work_stealing_pool.h>

THEP_NS_BEGIN

work_stealing_worker::work_stealing_worker(pool& p, worker_id id) noexcept
   : pool_{p}, id_{id}
{}

auto work_stealing_worker::launch() noexcept -> void {
}

auto work_stealing_worker::join() noexcept -> void {
}

auto work_stealing_worker::sched_job(job *job) noexcept -> void {
}

auto work_stealing_worker::steal_job() noexcept -> job* {
   return nullptr;
}

THEP_NS_END