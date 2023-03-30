#include "Span.hpp"

int main()
{
	Span sp = Span(10000000);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addRange(sp.getBegin(), sp.getEnd());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
