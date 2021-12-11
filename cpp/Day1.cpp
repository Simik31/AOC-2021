#include "Day1.h"

void Day1::part1()
{
    vector<string> lines;
    Utils::read_lines_from_file("../data/day1.txt", lines);
    
    int last = -1, count = 0;

    for (string line : lines)
    {
        int num = stoi(line);

        if (last > 0 && num > last)
            count++;
        last = num;
    }

    cout << "Day:  1 | Part: 1 | Result: " << count << endl;
}

void Day1::part2()
{
    vector<string> lines;
    Utils::read_lines_from_file("../data/day1.txt", lines);

    int last = -1, count = 0;

    for (size_t index = 0; index < lines.size() - 2; index++)
    {
        int sum = stoi(lines[index]) + stoi(lines[index + 1]) + stoi(lines[index + 2]);

        if (last > 0 && sum > last)
            count++;

        last = sum;
    }

    cout << "Day:  1 | Part: 2 | Result: " << count << endl;
}