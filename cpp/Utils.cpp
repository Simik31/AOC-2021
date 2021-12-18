#include "Utils.h"

 void Utils::read_lines_from_file(const string& filename, vector<string>& lines)
{
    ifstream file{ filename };

    if (!file.is_open())
    {
        perror("The following error occurred");
        exit(EXIT_FAILURE);
    }

    lines.clear();

    string line;
    while (getline(file, line))
        lines.push_back(line);
}

void Utils::split_string(const string& str, const char* sep, vector<string>& strings)
{
    string separator{ sep };
    size_t initialPos = 0;
    size_t pos;

    strings.clear();

    while ((pos = str.find(separator, initialPos)) != string::npos)
    {
        strings.push_back(str.substr(initialPos, pos - initialPos));
        initialPos = pos + separator.size();
    }

    strings.push_back(str.substr(initialPos, min(pos, str.size()) - initialPos + 1));
}

void Utils::split_string_regex(const string& str, const string& regex_str, vector<string>& strings)
{
    regex reg_ex{ regex_str };
    sregex_token_iterator iter{ str.begin(), str.end(), reg_ex, -1 };
    sregex_token_iterator end;

    strings.clear();

    while (iter != end)
        strings.push_back(*(iter++));
}