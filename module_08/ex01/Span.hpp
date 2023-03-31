#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include <cstddef>
#include <algorithm>

class Span {
	private:
	typedef std::vector<int>::iterator IT;
	public:
	Span(unsigned int n);
	Span(const Span &toCopy);
	~Span();
	Span &operator=(const Span &rhs);
	void			addNumber(int n);
	void			addRange(IT begin, IT end);
	class SpanIsFullException : public std::exception {
		public: virtual const char* what() const throw();
	};
	class SizeTooSmallException : public std::exception {
		public: virtual const char* what() const throw();
	};
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	std::vector<int>::iterator getBegin() {
		return this->vettore.begin();
	}
	std::vector<int>::iterator getEnd() {
		return this->vettore.end();
	}
	void	printVector();
	private:
	Span();
	std::vector<int>	vettore;
	std::size_t			size;
};
