#include "Day2.h"

void Day2::part1()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day2.txt", lines);

    int h_pos = 0, v_pos = 0;

    for (std::string line : lines)
    {
        std::vector<std::string> parts;
        Utils::split_string(line, " ", parts);
 
        std::string direction = parts[0];
        int value = std::stoi(parts[1]);

        if (direction == "forward")
            h_pos += value;
        else if (direction == "down")
            v_pos += value;
        else if (direction == "up")
            v_pos -= value;
        else exit(EXIT_FAILURE);
    }

    std::cout << "Day:  2 | Part: 1 | Result: " << h_pos * v_pos << std::endl;
}

void Day2::part2()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day2.txt", lines);

    int h_pos = 0, v_pos = 0, aim = 0;

    for (std::string line : lines)
    {
        std::vector<std::string> parts;
        Utils::split_string(line, " ", parts);

        std::string direction = parts[0];
        int value = std::stoi(parts[1]);

        if (direction == "forward")
        {
            h_pos += value;
            v_pos += aim * value;
        }
        else if (direction == "down")
            aim += value;
        else if (direction == "up")
            aim -= value;
        else exit(EXIT_FAILURE);
    }

    std::cout << "Day:  2 | Part: 2 | Result: " << h_pos * v_pos << std::endl;
}
