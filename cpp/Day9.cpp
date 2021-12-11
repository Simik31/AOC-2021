#include "Day9.h"

void Day9::part1()
{
    vector<vector<int>> height_map;
    vector<vector<bool>> lowest_truths;

    vector<string> lines;
    Utils::read_lines_from_file("../data/day9.txt", lines);
    
    for (string line : lines)
    {
        if (line != "")
        {
            height_map.push_back(vector<int>());
            lowest_truths.push_back(vector<bool>());

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
            vector<bool> truths;

            if (r >= 1)
                truths.push_back(height_map[r][c] < height_map[r - 1][c]);
            if (r + 1 < height_map.size())
                truths.push_back(height_map[r][c] < height_map[r + 1][c]);
            if (c >= 1)
                truths.push_back(height_map[r][c] < height_map[r][c - 1]);
            if (c + 1 < height_map[r].size())
                truths.push_back(height_map[r][c] < height_map[r][c + 1]);

            lowest_truths[r][c] = find(truths.begin(), truths.end(), false) == truths.end();
        }
    }

    int result = 0;

    for (int r = 0; r < height_map.size(); r++)
        for (int c = 0; c < height_map[r].size(); c++)
            if (lowest_truths[r][c])
                result += height_map[r][c] + 1;

    cout << "Day:  9 | Part: 1 | Result: " << result << endl;
}

int Day9::backtrack_basins(vector<vector<int>>& height_map, int r, int c, int counter, vector<pair<int, int>>& visited)
{
    if (find(visited.begin(), visited.end(), pair<int, int>(r, c)) != visited.end())
        return counter;

    visited.push_back(pair<int, int>(r, c));

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
    vector<vector<int>> height_map;
    vector<vector<bool>> lowest_truths;

    vector<string> lines;
    Utils::read_lines_from_file("../data/day9.txt", lines);

    for (string line : lines)
    {
        if (line != "")
        {
            height_map.push_back(vector<int>());
            lowest_truths.push_back(vector<bool>());

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
            vector<bool> truths;

            if (r >= 1)
                truths.push_back(height_map[r][c] < height_map[r - 1][c]);
            if (r + 1 < height_map.size())
                truths.push_back(height_map[r][c] < height_map[r + 1][c]);
            if (c >= 1)
                truths.push_back(height_map[r][c] < height_map[r][c - 1]);
            if (c + 1 < height_map[r].size())
                truths.push_back(height_map[r][c] < height_map[r][c + 1]);

            lowest_truths[r][c] = find(truths.begin(), truths.end(), false) == truths.end();
        }
    }

    vector<int> basins;
    vector<pair<int, int>> visited;

    for (int r = 0; r < height_map.size(); r++)
        for (int c = 0; c < height_map[r].size(); c++)
            if (lowest_truths[r][c])
                basins.push_back(Day9::backtrack_basins(height_map, r, c, 0, visited));

    sort(basins.begin(), basins.end());
    int result = basins[basins.size() - 1] * basins[basins.size() - 2] * basins[basins.size() - 3];

    cout << "Day:  9 | Part: 1 | Result: " << result << endl;
}