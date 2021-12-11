#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <regex>
#include <fstream>

using namespace std;

class Utils
{
public:
	static void read_lines_from_file(string filename, vector<string>& lines);
	static void split_string(string& str, const char* sep, vector<string>& strings);
	static void split_string_regex(string& str, string regex, vector<string>& strings);
};
#endif