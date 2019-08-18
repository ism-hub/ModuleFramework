
#pragma once

#include <utility>
#include "../Module.h"

#include <type_traits>

namespace MF {

template<class T, class M = void>
struct is_inherits_modulebase : std::false_type {};

template<class T>
struct is_inherits_modulebase<T, typename std::enable_if<std::is_base_of<ModuleBase, T>::value, void>::type > : std::true_type {};



template<class T, class M = void>
struct has_start : std::false_type {};

template <class T>
struct has_start<T, typename std::enable_if<std::is_member_function_pointer<decltype(&T::start)>::value, void>::type> : std::true_type {};



template<class T, bool f = true>
using enable_if_t_has_start_and_inherits_modulebase = typename std::enable_if<!f != (has_start<T>::value && is_inherits_modulebase<T>::value), void>::type;


};

