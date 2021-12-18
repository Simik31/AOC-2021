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
    static void read_lines_from_file(const string& filename, vector<string>& lines);
    static void split_string(const string& str, const char* sep, vector<string>& strings);
    static void split_string_regex(const string& str, const string& regex_str, vector<string>& strings);

    static size_t count_substring(const string& str, const string& substr);
};
#endif