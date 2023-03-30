#include "BitcoinExchange.hpp"

bool	isBisestile(int year) {
	if (year % 4 == 0) {
			if (year % 100 != 0)
				return true;
			else {
				if (year % 400 == 0)
					return true;
				else
					return false;
			}
		}
	else
		return false;
}

bool	checkValidDate(std::string date) {
	int	year;
	int	month;
	int	day;
	int firstMinus;
	int	secondMinus;

	firstMinus = date.find('-');
	secondMinus = date.find(firstMinus + 1, '-');
	year = std::atoi(date.substr(0, firstMinus).c_str());
	month = std::atoi(date.substr(firstMinus + 1, secondMinus).c_str());
	day = std::atoi(date.substr(firstMinus + 1, date.length()).c_str());
	if (year < 1900 || year > 2023 || month > 12 || month < 1 || day < 1)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	else if (month == 2 && ((isBisestile(year) == true && day > 29 ) || (isBisestile(year) == false && day > 28)))
		return false;
	return true;
}

BitcoinExchange::BitcoinExchange(std::string& dataFile, std::string& inputFile) {
	std::string		tmp;
	std::string		buffer;
	std::ifstream	dataFileFd;
	std::ifstream	inputFileFd;
	int				i = 0;

	dataFileFd.open(dataFile.c_str());
	if (dataFileFd.is_open() == false) {
		std::cout << "Can not open data file data.csv" << std::endl;
		exit (1);
	}
	inputFileFd.open(inputFile.c_str());
	if (inputFileFd.is_open() == false) {
		std::cout << "Can not open input file" << inputFile << std::endl;
		exit (1);
	}
	getline(dataFileFd, tmp);
	if (tmp != "date,exchange_rate") {
		std::cout << "Error, data files first column is not 'date,exchange_rate'" << std::endl;
		dataFileFd.close();
		exit (1);
	}

	while (getline(dataFileFd, buffer)) {
		std::string	when;
		double		value;
		when = buffer.substr(0, buffer.find(','));
		value = std::atof(buffer.substr(buffer.find(',') + 1, buffer.length()).c_str());		Contenitore	tmp(when, i);
		std::pair<Contenitore, double> tmpPair(tmp, value);
		this->dataTab.insert(tmpPair);
		i++;
	}

	getline(inputFileFd, tmp);
	if (tmp != "date | value") {
		std::cout << "Error, input files first column is not 'date | value'" << std::endl;
		exit (1);
	}
	i = 0;
	while (getline(inputFileFd, buffer)) {
		std::string	when;
		std::string	error = "Error: bad input => ";
		double		quantity;
		when = buffer.substr(0, buffer.find('|') - 1);
		if (checkValidDate(when) == false) 
			when = error + when; 
		quantity = std::atof(buffer.substr(buffer.find('|') + 1, buffer.length()).c_str());
		if (quantity < 0)
			when = "Error: not a positive number.";
		else if (quantity > 1000)
			when = "Error: too large a number";
		Contenitore	tmp(when, i);
		std::pair<Contenitore, double> tmpPair(tmp, quantity);
		this->inputTab.insert(tmpPair);
		i++;
	}
	dataFileFd.close();
	inputFileFd.close();
}

void    BitcoinExchange::printDataTab() {
    std::cout.precision(7);
    std::multimap<Contenitore, double>::const_iterator  it;
    for (it = this->dataTab.begin(); it != this->dataTab.end(); it++) {
        std::cout << it->first << " - " << it->second << std::endl;
    }
}

void    BitcoinExchange::printInputTab() {
    std::cout.precision(7);
    std::multimap<Contenitore, double>::const_iterator  it;
    for (it = this->inputTab.begin(); it != this->inputTab.end(); it++) {
        std::cout << it->first << " - " << it->second << std::endl;
    }
}

void	BitcoinExchange::printResults() {
	std::string	check = "Error";
	std::multimap<Contenitore, double>::const_iterator  it;
	std::multimap<Contenitore, double>::const_iterator  it2;
    for (it = this->inputTab.begin(); it != this->inputTab.end(); it++) {
        if ((*it).first.data.find(check) != std::string::npos) {
			std::cout << (*it).first << std::endl;
		}
		else {
			it2 = this->dataTab.begin();
			while ((*it2).first.data < (*it).first.data) {
				it2++;
			}
			if ((*it2).first.data > (*it).first.data)
				it2--;
			std::cout << (*it).first.data << " => " << (*it).second << " = " << (*it).second * (*it2).second << std::endl;
		}
    }
}

Contenitore::Contenitore(std::string data, int idx) {
	this->data = data;
	this->idx = idx;
}

bool operator<(const Contenitore &c1, const Contenitore &c2) {
    return c1.idx < c2.idx;
}

std::ostream&   operator<<(std::ostream &os, const Contenitore &c) {
	os << c.data;
    return os;
}
