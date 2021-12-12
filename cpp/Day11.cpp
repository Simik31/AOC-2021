#include "Day11.h"

void Day11::flash(vector<vector<pair<int, bool>>>& grid, int x, int y, int& counter)
{
	if (grid[y][x].second == true)
		return;

	grid[y][x].first += 1;

	if (grid[y][x].first > 9)
	{
		grid[y][x].first = 0;
		grid[y][x].second = true;
		counter++;

		for (int y_off = -1; y_off < 2; y_off++)
			for (int x_off = -1; x_off < 2; x_off++)
				if (y + y_off >= 0 && y + y_off < grid.size() && x + x_off >= 0 && x + x_off < grid[y + y_off].size())
					Day11::flash(grid, x + x_off, y + y_off, counter);
	}
}

void Day11::part1()
{
	vector<vector<pair<int, bool>>> grid;

	vector<string> lines;
	Utils::read_lines_from_file("../data/day11.txt", lines);

	for (string line : lines)
	{
		grid.push_back(vector<pair<int, bool>>());
		for (char& num : line)
			grid.back().push_back(pair<int, bool>(num - '0', false));
	}

	int counter = 0;


	for (int step = 1; step <= 100; step++)
	{
		for (int row = 0; row < grid.size(); row++)
			for (int col = 0; col < grid[row].size(); col++)
				grid[row][col].second = false;

		for (int row = 0; row < grid.size(); row++)
			for (int col = 0; col < grid[row].size(); col++)
				flash(grid, col, row, counter);
	}

	cout << "Day: 11 | Part: 1 | Result: " << counter << endl;
}

void Day11::part2()
{
	vector<vector<pair<int, bool>>> grid;

	vector<string> lines;
	Utils::read_lines_from_file("../data/day11.txt", lines);

	for (string line : lines)
	{
		grid.push_back(vector<pair<int, bool>>());
		for (char& num : line)
			grid.back().push_back(pair<int, bool>(num - '0', false));
	}

	int ignore = 0;
	int step = 0;
	bool all_true = false;

	for (; !all_true; step++)
	{
		for (int row = 0; row < grid.size(); row++)
			for (int col = 0; col < grid[row].size(); col++)
				grid[row][col].second = false;

		for (int row = 0; row < grid.size(); row++)
			for (int col = 0; col < grid[row].size(); col++)
				flash(grid, col, row, ignore);

		all_true = true;
		for (int row = 0; all_true && row < grid.size(); row++)
			for (int col = 0; all_true && col < grid[row].size(); col++)
				if (grid[row][col].second == false)
					all_true = false;
	}

	cout << "Day: 11 | Part: 2 | Result: " << step << endl;
}