#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : size(n) {

}

Span::Span(const Span &toCopy) : vettore(toCopy.vettore), size(toCopy.size) {
	*this = toCopy;
}

Span::~Span() {}

Span	&Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->size = rhs.size;
		this->vettore = rhs.vettore;
	}
	return *this;
}

void	Span::addNumber(int n) {
	if (this->vettore.size() >= this->size) {
		throw Span::SpanIsFullException();
	}
	this->vettore.push_back(n);
}

void	Span::addRange(IT begin, IT end) {
	if (this->vettore.size() + std::distance(begin, end) > this->size) {
		throw Span::SpanIsFullException();
	}
	this->vettore.insert(this->vettore.end(), begin, end);
}

const char *Span::SpanIsFullException::what() const throw() {
	return ("Can not add number cause span is full!");
}

const char *Span::SizeTooSmallException::what() const throw() {
	return ("Size of span is 1 or less, no span to find!");
}

unsigned int	Span::longestSpan() {
	if (this->vettore.size() < 2) {
		throw Span::SizeTooSmallException();
	}
	return *std::max_element(this->vettore.begin(), this->vettore.end()) - *std::min_element(this->vettore.begin(), this->vettore.end());
}

unsigned int	Span::shortestSpan() {
	if (this->vettore.size() < 2) {
		throw Span::SizeTooSmallException();
	}
	std::vector<int> sorted = this->vettore;
	std::sort(sorted.begin(), sorted.end());
	int res = sorted[1] - sorted[0];
	for (size_t i = 0; i < sorted.size() - 1; i++) {
		if (res > sorted[i + 1] - sorted[i]) {
			res = sorted[i + 1] - sorted[i];
		}
	}
	return res;
}
