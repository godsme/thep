//
// Created by Darwin Yuan on 2020/9/19.
//

#include <thep/core/work_strealing/work_stealing_worker.h>
#include <thep/core/work_strealing/work_stealing_pool.h>
#include <thep/core/resumable.h>

THEP_NS_BEGIN

////////////////////////////////////////////////////////////////////////////
work_stealing_worker::work_stealing_worker(worker_id id, pool& p) noexcept
   : pool_{p}, id_{id}
{}

////////////////////////////////////////////////////////////////////////////
auto work_stealing_worker::get_a_job() noexcept -> resumable* {
   if(auto job = take_a_job(); job != nullptr) return job;
   return pool_.try_steal(id_);
}

////////////////////////////////////////////////////////////////////////////
auto work_stealing_worker::resume_once(resumable* job) noexcept -> bool {
   if(job->resume()) {
      job->release();
      return true;
   } else {
      return job_queue_.reschedule(job);
   }
}

////////////////////////////////////////////////////////////////////////////
auto work_stealing_worker::resume_job(resumable* job) noexcept -> void {
   while(!resume_once(job)) {
      if(pool_.shutdown_notified()) {
         job->release();
         return;
      }
   }
}

////////////////////////////////////////////////////////////////////////////
auto work_stealing_worker::run() -> void {
   while (1) {
      if(pool_.shutdown_notified()) return;
      auto job = get_a_job();
      if(job != nullptr) {
         resume_job(job);
      }
   }
}

////////////////////////////////////////////////////////////////////////////
auto work_stealing_worker::launch() noexcept -> void {
   thread_ = std::thread{[this]{ run(); }};
}

////////////////////////////////////////////////////////////////////////////
auto work_stealing_worker::join() noexcept -> void {
   thread_.join();
}

////////////////////////////////////////////////////////////////////////////
auto work_stealing_worker::sched_job(resumable *job) noexcept -> void {
   job_queue_.enqueue(job);
}

auto work_stealing_worker::take_a_job() noexcept -> resumable* {
   return job_queue_.dequeue<resumable>();
}

THEP_NS_END