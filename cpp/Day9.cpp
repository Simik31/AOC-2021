#include "Day9.h"

void Day9::part1()
{
    std::vector<std::vector<int>> height_map;
    std::vector<std::vector<bool>> lowest_truths;

    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day9.txt", lines);
    
    for (std::string line : lines)
    {
        if (line != "")
        {
            height_map.push_back(std::vector<int>());
            lowest_truths.push_back(std::vector<bool>());

            for (char& num : line)
            {
                height_map.back().push_back(num - '0');
                lowest_truths.back().push_back(false);
            }
        }
    }

    for (int r = 0; r < height_map.size(); r++)
    {
        for (int c = 0; c < height_map[r].size(); c++)
        {
            std::vector<bool> truths;

            if (r >= 1)
                truths.push_back(height_map[r][c] < height_map[r - 1][c]);
            if (r + 1 < height_map.size())
                truths.push_back(height_map[r][c] < height_map[r + 1][c]);
            if (c >= 1)
                truths.push_back(height_map[r][c] < height_map[r][c - 1]);
            if (c + 1 < height_map[r].size())
                truths.push_back(height_map[r][c] < height_map[r][c + 1]);

            lowest_truths[r][c] = std::find(truths.begin(), truths.end(), false) == truths.end();
        }
    }

    int result = 0;

    for (int r = 0; r < height_map.size(); r++)
        for (int c = 0; c < height_map[r].size(); c++)
            if (lowest_truths[r][c])
                result += height_map[r][c] + 1;

    std::cout << "Day:  9 | Part: 1 | Result: " << result << std::endl;
}

int Day9::backtrack_basins(std::vector<std::vector<int>>& height_map, int r, int c, int counter, std::vector<std::pair<int, int>>& visited)
{
    if (std::find(visited.begin(), visited.end(), std::pair<int, int>(r, c)) != visited.end())
        return counter;

    visited.push_back(std::pair<int, int>(r, c));

    if (height_map[r][c] == 9)
        return counter;

    counter++;

    if (r >= 1)
        counter = Day9::backtrack_basins(height_map, r - 1, c, counter, visited);
    if (r + 1 < height_map.size())
        counter = Day9::backtrack_basins(height_map, r + 1, c, counter, visited);
    if (c >= 1)
        counter = Day9::backtrack_basins(height_map, r, c - 1, counter, visited);
    if (c + 1 < height_map[r].size())
        counter = Day9::backtrack_basins(height_map, r, c + 1, counter, visited);

    return counter;
}

void Day9::part2()
{
    std::vector<std::vector<int>> height_map;
    std::vector<std::vector<bool>> lowest_truths;

    std::vector<std::string> lines;
    Utils::read_lines_from_file("../data/day9.txt", lines);

    for (std::string line : lines)
    {
        if (line != "")
        {
            height_map.push_back(std::vector<int>());
            lowest_truths.push_back(std::vector<bool>());

            for (char& num : line)
            {
                height_map.back().push_back(num - '0');
                lowest_truths.back().push_back(false);
            }
        }
    }

    for (int r = 0; r < height_map.size(); r++)
    {
        for (int c = 0; c < height_map[r].size(); c++)
        {
            std::vector<bool> truths;

            if (r >= 1)
                truths.push_back(height_map[r][c] < height_map[r - 1][c]);
            if (r + 1 < height_map.size())
                truths.push_back(height_map[r][c] < height_map[r + 1][c]);
            if (c >= 1)
                truths.push_back(height_map[r][c] < height_map[r][c - 1]);
            if (c + 1 < height_map[r].size())
                truths.push_back(height_map[r][c] < height_map[r][c + 1]);

            lowest_truths[r][c] = std::find(truths.begin(), truths.end(), false) == truths.end();
        }
    }

    std::vector<int> basins;
    std::vector<std::pair<int, int>> visited;

    for (int r = 0; r < height_map.size(); r++)
        for (int c = 0; c < height_map[r].size(); c++)
            if (lowest_truths[r][c])
                basins.push_back(Day9::backtrack_basins(height_map, r, c, 0, visited));

    std::sort(basins.begin(), basins.end());
    int result = basins[basins.size() - 1] * basins[basins.size() - 2] * basins[basins.size() - 3];

    std::cout << "Day:  9 | Part: 1 | Result: " << result << std::endl;
}