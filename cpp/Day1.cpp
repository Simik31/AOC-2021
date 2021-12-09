#include "Day1.h"

void Day1::part1()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day1.txt", lines);
    
    int last = -1;
    int count = 0;

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

    std::vector<int> sums;
    for (size_t index = 0; index < lines.size() - 2; index++)
    {
        int sum = 0;

        for (int off = 0; off < 3; off++)
            sum += std::stoi(lines[index + off]);
        sums.push_back(sum);
    }

    int last = -1;
    int count = 0;

    for (int sum : sums)
    {
        if (last > 0 && sum > last)
            count++;
        last = sum;
    }

    std::cout << "Day:  1 | Part: 2 | Result: " << count << std::endl;
}