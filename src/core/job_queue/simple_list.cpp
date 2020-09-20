//
// Created by Darwin Yuan on 2020/9/20.
//

#include <thep/job_queue/simple_list.h>

THEP_NS_BEGIN

/////////////////////////////////////////////////////////////////////////
auto simple_list::enqueue(list_element* ptr) noexcept -> void {
   if(tail_ != nullptr) tail_->next = ptr;
   else head_ = ptr;
   tail_ = ptr;
   ptr->next = nullptr;
}

/////////////////////////////////////////////////////////////////////////
auto simple_list::push_front(list_element* ptr) noexcept -> void {
   if(tail_ == nullptr) tail_ = ptr;
   ptr->next = head_;
   head_ = ptr;
}

/////////////////////////////////////////////////////////////////////////
auto simple_list::empty() const noexcept -> bool {
   return head_ == nullptr;
}

/////////////////////////////////////////////////////////////////////////
simple_list::~simple_list() {
   for(auto elem = pop_front(); elem != nullptr; elem = pop_front()) {
      delete elem;
   }
}

/////////////////////////////////////////////////////////////////////////
auto simple_list::pop_front() noexcept -> list_element* {
   if(head_ == nullptr) return nullptr;
   auto elem = head_;
   head_ = elem->next;
   if (head_ == nullptr) tail_ = nullptr;
   return elem;
}

THEP_NS_END