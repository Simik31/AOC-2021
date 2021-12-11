#include "Day7.h"

void Day7::part1()
{
    vector<string> lines;
    Utils::read_lines_from_file("../data/day7.txt", lines);

    vector<int> positions;
    set<int> positions_set;

    vector<string> num_s_v;
    Utils::split_string(lines[0], ",", num_s_v);

    for (string num_s : num_s_v)
    {
        positions.push_back(stoi(num_s));
        positions_set.insert(stoi(num_s));
    }

    int min_cost = numeric_limits<int>::max();

    for (int end_position : positions_set)
    {
        int position_cost = 0;
        for (int crab_position : positions)
            position_cost += abs(end_position - crab_position);

        if (position_cost < min_cost) min_cost = position_cost;
    }

    cout << "Day:  7 | Part: 1 | Result: " << min_cost << endl;
}

void Day7::part2()
{
    vector<string> lines;
    Utils::read_lines_from_file("../data/day7.txt", lines);

    vector<int> positions;
    set<int> positions_set;
    int max_position = 0;

    vector<string> num_s_v;
    Utils::split_string(lines[0], ",", num_s_v);

    for (string num_s : num_s_v)
    {
        int position = stoi(num_s);

        positions.push_back(position);
        positions_set.insert(position);

        if (position > max_position) max_position = position;
    }

    int min_cost = numeric_limits<int>::max();

    for (int end_position = 1; end_position < max_position; end_position++)
    {
        int position_cost = 0;

        for (int crab_position : positions)
            for (int step = 1; step <= abs(end_position - crab_position); step++)
                position_cost += step;

        if (position_cost < min_cost) min_cost = position_cost;
    }

    cout << "Day:  7 | Part: 2 | Result: " << min_cost << endl;
}