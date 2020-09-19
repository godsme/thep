cmake_minimum_required(VERSION 3.17)
project(thep)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/third-party"
)

add_executable(thep main.cpp include/thep/thep_ns.h include/thep/core/job.h include/thep/core/work_strealing/work_stealing_pool.h src/core/work_stealing/work_strealing_pool.cpp include/thep/core/work_strealing/work_stealing_worker.h src/core/work_stealing/work_stealing_worker.cpp)