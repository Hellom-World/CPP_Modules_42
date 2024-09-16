#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>

bool    open_file(std::ifstream &file, const char *filename, int flag);
void    print_file(std::ifstream &file);
bool    valid_date_format(std::string date);
bool    valid_value(std::string value);
void    make_data(const char *filename, std::map<std::string, float> &data);
void    print_map(std::map<std::string, float> &data);
void    open_input_file(char **argv, std::ifstream &file);
void    line_verify(std::string line, std::string date, std::string value, std::map<std::string, float> &data);

#endif
