//
// Created by Darwin Yuan on 2020/9/20.
//

#ifndef THEP_SIMPLE_LIST_ELEMENT_H
#define THEP_SIMPLE_LIST_ELEMENT_H

#include <thep/thep_ns.h>

THEP_NS_BEGIN

struct simple_list_element {
   simple_list_element* next{};

   virtual ~simple_list_element() = default;

   template<typename T>
   auto to_value() -> T* {
      return reinterpret_cast<T*>(to_value_ptr());
   }
private:
   virtual auto to_value_ptr() -> void* = 0;
};

THEP_NS_END

#endif //THEP_SIMPLE_LIST_ELEMENT_H
