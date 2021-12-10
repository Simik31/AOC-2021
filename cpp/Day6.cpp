#include "Day6.h"

void Day6::part1()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day6.txt", lines);
       
    std::map<int, int> ages;
    std::vector<std::string> num_s_v;
    Utils::split_string(lines[0], ",", num_s_v);

    for (int age = -1; age < 9; age++)
        ages.insert(std::pair<int, int>(age, 0));

    for (std::string num_s : num_s_v)
    {
        ages[std::stoi(num_s)]++;
    }

    for (int day = 0; day < 80; day++)
    {
        for (int age = -1; age < 8; age++)
            ages[age] = ages[age + 1];
        ages[6] += ages[-1];
        ages[8] = ages[-1];
    }

    int result = 0;
    for (int age = 0; age < 9; age++)
        result += ages[age];

    std::cout << "Day:  6 | Part: 1 | Result: " << result << std::endl;
}

void Day6::part2()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day6.txt", lines);

    std::map<int, long long> ages;
    std::vector<std::string> num_s_v;
    Utils::split_string(lines[0], ",", num_s_v);

    for (int age = -1; age < 9; age++)
        ages.insert(std::pair<int, long long>(age, 0L));

    for (std::string num_s : num_s_v)
    {
        ages[std::stoi(num_s)]++;
    }

    for (int day = 0; day < 256; day++)
    {
        for (int age = -1; age < 8; age++)
            ages[age] = ages[age + 1];
        ages[6] += ages[-1];
        ages[8] = ages[-1];
    }

    long long result = 0;
    for (int age = 0; age < 9; age++)
        result += ages[age];

    std::cout << "Day:  6 | Part: 2 | Result: " << result << std::endl;
}
