#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <algorithm>
# include <fstream>

class  Contenitore {
	private:
	Contenitore();
	public:
	std::string data;
	int         idx;
	Contenitore(std::string data, int idx);
};


class   BitcoinExchange {
	private:
	BitcoinExchange();
	public:
	std::map<Contenitore, double>		dataTab;
	std::map<Contenitore, double>		inputTab;
	BitcoinExchange(std::string& dataFile, std::string& inputFile);
	void	printDataTab();
	void	printInputTab();
	void	printResults();
};

bool operator<(const Contenitore &c1, const Contenitore &c2);
std::ostream& operator<<(std::ostream &os, const Contenitore &c);

#endif