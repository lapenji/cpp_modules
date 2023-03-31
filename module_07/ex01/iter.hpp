#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cctype>

template<typename T>

void	iter(T *arr, size_t length, void (*f)(T const &param)) {
	for (size_t i = 0; i < length; i++) {
		(*f)(arr[i]);
	}
}

template<typename T>
void	printContent(T const &val) {
	std::cout << val << std::endl;
}

#endif