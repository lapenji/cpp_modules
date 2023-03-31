#include "PmergeMe.hpp"

bool    checkIfDigits(std::string input) {
	for (int i = 0; i < int(input.length()); i++) {
		if (isdigit(input[i]) == false)
			return false;
	}
	return true;
}

PmergeMe::PmergeMe(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		if (checkIfDigits(argv[i]) == false) {
			std::cout << "Error: " << argv[i] << " parameter is wrong!" << std::endl;
			exit (1);
		}
		this->vettore.push_back(std::atoi(argv[i]));
		this->deque.push_back(std::atoi(argv[i]));
	}
}

void    PmergeMe::printVector() {
	for (std::vector<int>::iterator it = this->vettore.begin(); it < this->vettore.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void    PmergeMe::printDeque() {
	for (std::deque<int>::iterator it = this->deque.begin(); it < this->deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::mergeMeVandD() {
	struct timeval start;
	struct timeval	end;
	long			seconds;
	long			microseconds;
	long			actualTime;
	gettimeofday(&start, NULL);
	mergeSortV(this->vettore, 0, this->vettore.size() - 1);
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	actualTime = (seconds / 1000000) + microseconds;
	std::cout << "time for processing a vector of " << this->vettore.size() << " members = " << actualTime << "us" << std::endl;
	gettimeofday(&start, NULL);
	mergeSortD(this->deque, 0, this->vettore.size() - 1);
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	actualTime = (seconds / 1000000) + microseconds;
	std::cout << "time for processing a deque of " << this->vettore.size() << " members = " << actualTime << "us" << std::endl;
}

void    doTheMergeD(std::deque<int> &deque, int start, int mezzo, int end) {	
	int					i;
	int					b;
	std::deque<int>	tmp;

	i = start;
	b = mezzo + 1;
	while (i <= mezzo && b <= end) {
		if (deque[i] <= deque[b]) {
			tmp.push_back(deque[i]);
			i++;
		}
		else {
			tmp.push_back(deque[b]);
			b++;
		}
	}

	while (i <= mezzo) {
		tmp.push_back(deque[i]);
		i++;
	}

	while (b <= end) {
		tmp.push_back(deque[b]);
		b++;
	}

	for (int x = start; x <= end; x++) {
		deque[x] = tmp[x - start];
	}
}


void    doTheMergeV(std::vector<int> &vettore, int start, int mezzo, int end) {	
	int					i;
	int					b;
	std::vector<int>	tmp;

	i = start;
	b = mezzo + 1;
	while (i <= mezzo && b <= end) {
		if (vettore[i] <= vettore[b]) {
			tmp.push_back(vettore[i]);
			i++;
		}
		else {
			tmp.push_back(vettore[b]);
			b++;
		}
	}

	while (i <= mezzo) {
		tmp.push_back(vettore[i]);
		i++;
	}

	while (b <= end) {
		tmp.push_back(vettore[b]);
		b++;
	}

	for (int x = start; x <= end; x++) {
		vettore[x] = tmp[x - start];
	}
}
void	mergeSortV(std::vector<int> &vettore, int start, int end) {
	if (start < end) {
		int mezzo = (start + end) / 2;
		mergeSortV(vettore, start, mezzo);
		mergeSortV(vettore, mezzo + 1, end);
		doTheMergeV(vettore, start, mezzo, end);
	}
}

void	mergeSortD(std::deque<int> &deque, int start, int end) {
	if (start < end) {
		int mezzo = (start + end) / 2;
		mergeSortD(deque, start, mezzo);
		mergeSortD(deque, mezzo + 1, end);
		doTheMergeD(deque, start, mezzo, end);
	}
}