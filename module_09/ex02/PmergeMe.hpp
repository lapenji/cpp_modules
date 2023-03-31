#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <sys/time.h>
# include <iostream>
# include <vector>
# include <cstdlib>
# include <deque>


class PmergeMe {
	private:
	PmergeMe();
	std::vector<int>    vettore;
	std::deque<int>		deque;

	public:

	bool				ok;	
	PmergeMe(int argc, char **argv);
	void    printVector();
	void	mergeMeVandD();
	void	printDeque();
};
void	mergeSortV(std::vector<int> &vettore, int start, int end);
void	mergeSortD(std::deque<int> &deque, int start, int end);

#endif