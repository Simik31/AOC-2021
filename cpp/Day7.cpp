#include "Day7.h"

void Day7::part1()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day7.txt", lines);

    std::vector<int> positions;
    std::set<int> positions_set;

    std::vector<std::string> num_s_v;
    Utils::split_string(lines[0], ",", num_s_v);

    for (std::string num_s : num_s_v)
    {
        positions.push_back(std::stoi(num_s));
        positions_set.insert(std::stoi(num_s));
    }

    int min_cost = std::numeric_limits<int>::max();

    for (int end_position : positions_set)
    {
        int position_cost = 0;
        for (int crab_position : positions)
            position_cost += abs(end_position - crab_position);

        if (position_cost < min_cost) min_cost = position_cost;
    }

    std::cout << "Day:  7 | Part: 1 | Result: " << min_cost << std::endl;
}

void Day7::part2()
{
    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day7.txt", lines);

    std::vector<int> positions;
    std::set<int> positions_set;
    int max_position = 0;

    std::vector<std::string> num_s_v;
    Utils::split_string(lines[0], ",", num_s_v);

    for (std::string num_s : num_s_v)
    {
        int position = std::stoi(num_s);

        positions.push_back(position);
        positions_set.insert(position);

        if (position > max_position) max_position = position;
    }

    int min_cost = std::numeric_limits<int>::max();

    for (int end_position = 1; end_position < max_position; end_position++)
    {
        int position_cost = 0;

        for (int crab_position : positions)
            for (int step = 1; step <= abs(end_position - crab_position); step++)
                position_cost += step;

        if (position_cost < min_cost) min_cost = position_cost;
    }

    std::cout << "Day:  7 | Part: 2 | Result: " << min_cost << std::endl;
}