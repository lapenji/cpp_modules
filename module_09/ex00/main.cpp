#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "One paramater, input file" << std::endl;
		exit(1);
	}
	std::string dataFile = "data.csv";
	std::string inputFile = argv[1];
	BitcoinExchange ciccio(dataFile, inputFile);
	ciccio.printResults();
}