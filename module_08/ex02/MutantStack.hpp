#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <list>
# include <stack>
# include <algorithm>
# include <iterator>

template <class Type, class Container = std::deque<Type> >

class MutantStack : public std::stack<Type, Container> {
	public:
	MutantStack() : std::stack<Type, Container>() {}
	MutantStack( const MutantStack &toCopy) : std::stack<Type, Container> (toCopy) {}
	MutantStack &operator=(const MutantStack &rhs) {
		if (this != &rhs) {
			this->c = rhs.c;
		}
		return (*this);
	}
	typedef typename std::stack<Type, Container>::container_type::iterator iterator;
	iterator	begin() { return this->c.begin();}
	iterator	end() { return this->c.end();}
};

#endif