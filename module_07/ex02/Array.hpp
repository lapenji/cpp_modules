#pragma once

#include <iostream>
#include <exception>
#include <cctype>

template <typename T>
class Array {
	private:
	size_t	length;
	T		*elements;
	public:
	Array();
	Array(size_t length);
	Array(const Array<T> &toCopy);
	virtual	~Array();
	Array &operator=(const Array<T> &rhs);
	T	&operator[](size_t idx);
	T const &operator[](size_t index) const;
	size_t	size(void) const;
	class OobExc : public std::exception {
		virtual const char* what() const throw();
	};
};

#include "Array.tpp"
