#include "Day2.h"

void Day2::part1()
{
    vector<string> lines;
    Utils::read_lines_from_file("../data/day2.txt", lines);

    int h_pos = 0, v_pos = 0;

    for (string line : lines)
    {
        vector<string> parts;
        Utils::split_string(line, " ", parts);
 
        string direction = parts[0];
        int value = stoi(parts[1]);

        if (direction == "forward")
            h_pos += value;
        else if (direction == "down")
            v_pos += value;
        else if (direction == "up")
            v_pos -= value;
        else exit(EXIT_FAILURE);
    }

    cout << "Day:  2 | Part: 1 | Result: " << h_pos * v_pos << endl;
}

void Day2::part2()
{
    vector<string> lines;
    Utils::read_lines_from_file("../data/day2.txt", lines);

    int h_pos = 0, v_pos = 0, aim = 0;

    for (string line : lines)
    {
        vector<string> parts;
        Utils::split_string(line, " ", parts);

        string direction = parts[0];
        int value = stoi(parts[1]);

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

    cout << "Day:  2 | Part: 2 | Result: " << h_pos * v_pos << endl;
}
