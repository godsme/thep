//
// Created by Darwin Yuan on 2020/9/20.
//

#ifndef THEP_SIMPLE_LIST_H
#define THEP_SIMPLE_LIST_H

#include <thep/job_queue/simple_list_element.h>

THEP_NS_BEGIN

struct simple_list {
   using list_element = simple_list_element;

   auto enqueue(list_element* ptr) noexcept -> void;
   auto push_front(list_element* ptr) noexcept -> void;
   auto empty() const noexcept -> bool;
   auto pop_front() noexcept -> list_element*;

   ~simple_list();

private:
   list_element* head_ {};
   list_element* tail_ {};
};

THEP_NS_END

#endif //THEP_SIMPLE_LIST_H
