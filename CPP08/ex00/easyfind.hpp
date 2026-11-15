#pragma once
#include <stdexcept>
#include <algorithm>

template<typename T>
typename T::const_iterator	easyfind(const T &container, int valueToFind);

#include "easyfind.tpp"
