#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator ret = std::find(container.begin(), container.end(), value);
	return ret;
}
