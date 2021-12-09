#include "Utils.h"

void Utils::read_lines_from_file(std::string filename, std::vector<std::string>& lines)
{
    std::ifstream file;
    file.open(filename);

    if (!file.is_open())
    {
        perror("The following error occurred");
        exit(EXIT_FAILURE);
    }

    lines.clear();

    std::string line;
    while (getline(file, line))
        lines.push_back(line);

    file.close();
}

void Utils::split_string(std::string& str, const char* sep, std::vector<std::string>& strings)
{
    std::string separator = std::string(sep);
    size_t initialPos = 0;
    size_t pos;

    strings.clear();

    while ((pos = str.find(separator, initialPos)) != std::string::npos)
    {
        strings.push_back(str.substr(initialPos, pos - initialPos));
        initialPos = pos + separator.size();
    }

    strings.push_back(str.substr(initialPos, std::min(pos, str.size()) - initialPos + 1));
}

void Utils::split_string_regex(std::string& str, std::string regex, std::vector<std::string>& strings)
{
    std::regex rgx(regex);
    std::sregex_token_iterator iter(str.begin(), str.end(), rgx, -1);
    std::sregex_token_iterator end;

    strings.clear();

    while (iter != end)
        strings.push_back(*(iter++));
}