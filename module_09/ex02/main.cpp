#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "not enough parameters!" << std::endl;
    }
    PmergeMe    ciccio(argc, argv);
    std::cout << "VECTOR PRIMA DEL MERGE SORT" << std::endl; 
    ciccio.printVector();
    std::cout << "DEQUE PRIMA DEL MERGE SORT" << std::endl;
    ciccio.printDeque();
    ciccio.mergeMeVandD();
    std::cout << "VECTOR DOPO IL MERGE SORT" << std::endl; 
    ciccio.printVector();
    std::cout << "DEQUE DOPO IL MERGE SORT" << std::endl;
    ciccio.printDeque();

}