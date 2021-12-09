#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <regex>
#include <fstream>

class Utils
{
public:
	static void read_lines_from_file(std::string filename, std::vector<std::string>& lines);
	static void split_string(std::string& str, const char* sep, std::vector<std::string>& strings);
	static void split_string_regex(std::string& str, std::string regex, std::vector<std::string>& strings);
};
#endif