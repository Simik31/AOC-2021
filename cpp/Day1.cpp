#include "Day1.h"

void Day1::part1()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day1.txt", lines);
    
    int last = -1, count = 0;

    for (std::string line : lines)
    {
        int num = std::stoi(line);

        if (last > 0 && num > last)
            count++;
        last = num;
    }

    std::cout << "Day:  1 | Part: 1 | Result: " << count << std::endl;
}

void Day1::part2()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day1.txt", lines);

    int last = -1, count = 0;

    for (size_t index = 0; index < lines.size() - 2; index++)
    {
        int sum = std::stoi(lines[index]) + std::stoi(lines[index + 1]) + std::stoi(lines[index + 2]);

        if (last > 0 && sum > last)
            count++;

        last = sum;
    }

    std::cout << "Day:  1 | Part: 2 | Result: " << count << std::endl;
}