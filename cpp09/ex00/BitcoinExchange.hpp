#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <limits>
#include <cerrno>
#include <fstream>
#include <cstdlib>

void	convert_bitcoin(std::ifstream &file, std::map<std::string, float> db);

#endif
