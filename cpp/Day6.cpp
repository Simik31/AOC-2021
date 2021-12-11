#include "Day6.h"

void Day6::part1()
{
    vector<string> lines;
    Utils::read_lines_from_file("../data/day6.txt", lines);
       
    map<int, int> ages;
    vector<string> num_s_v;
    Utils::split_string(lines[0], ",", num_s_v);

    for (int age = -1; age < 9; age++)
        ages.insert(pair<int, int>(age, 0));

    for (string num_s : num_s_v)
    {
        ages[stoi(num_s)]++;
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

    cout << "Day:  6 | Part: 1 | Result: " << result << endl;
}

void Day6::part2()
{
    vector<string> lines;
    Utils::read_lines_from_file("../data/day6.txt", lines);

    map<int, long long> ages;
    vector<string> num_s_v;
    Utils::split_string(lines[0], ",", num_s_v);

    for (int age = -1; age < 9; age++)
        ages.insert(pair<int, long long>(age, 0L));

    for (string num_s : num_s_v)
    {
        ages[stoi(num_s)]++;
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

    cout << "Day:  6 | Part: 2 | Result: " << result << endl;
}
