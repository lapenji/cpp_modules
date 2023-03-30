#include "main.hpp"

int	main(int argc, char **argv) {
	std::ifstream	fd_orig;
	std::ofstream	fd_replaced;
	std::string		replaced_name;
	std::string		currentLine;
	std::string		line;
	std::string		toFind;
	std::string		toPut;

	if (argc != 4) {
		std::cout << "wrong number of params!" << std::endl;
		return (1);
	}
	replaced_name = argv[1];
	replaced_name.append(".replaced");
	fd_orig.open(argv[1]);
	if (fd_orig.fail()) {
		std::cout << "Error" << std::endl;
		std::cout << "can not open infile" << std::endl;
		return (1);
	}
	fd_replaced.open(replaced_name.c_str());
	if (fd_replaced.fail()) {
		std::cout << "Error" << std::endl;
		std::cout << "can not create outfile" << std::endl;
		return (1);
	}
	toFind = argv[2];
	toPut = argv[3];
	while (getline(fd_orig, line)) {
		size_t	pos;
		pos = line.find(argv[2], 0);
		if (pos != std::string::npos){
			line.erase(pos, toFind.length());
			line.insert(pos, toPut);
		}
		fd_replaced << line;
		fd_replaced << std::endl;
	}
}
