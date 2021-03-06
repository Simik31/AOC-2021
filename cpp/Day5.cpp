#include "Day5.h"

void Day5::part1()
{
	vector<int> x1;
	vector<int> y1;
	vector<int> x2;
	vector<int> y2;

	vector<string> lines;
	Utils::read_lines_from_file("../data/day5.txt", lines);

	vector<string> points, one, two;
	for (string line : lines)
	{
		Utils::split_string(line, " -> ", points);
		Utils::split_string(points[0], ",", one);
		Utils::split_string(points[1], ",", two);

		x1.push_back(stoi(one[0]));
		y1.push_back(stoi(one[1]));
		x2.push_back(stoi(two[0]));
		y2.push_back(stoi(two[1]));
	}

	int max_x = max(
		*max_element(x1.begin(), x1.end()),
		*max_element(x2.begin(), x2.end())
	);
	int max_y = max(
		*max_element(y1.begin(), y1.end()),
		*max_element(y2.begin(), y2.end())
	);

	vector<vector<int>> vents;

	for (int y = 0; y <= max_y; y++)
	{
		vents.push_back(vector<int>());
		for (int x = 0; x <= max_x; x++)
			vents[y].push_back(0);
	}

	for (int index = 0; index < x1.size(); index++)
	{
		int x_one = x1[index];
		int y_one = y1[index];
		int x_two = x2[index];
		int y_two = y2[index];

		if (x_one > x_two) swap(x_one, x_two);
		if (y_one > y_two) swap(y_one, y_two);

		if (x_one == x_two)
			for (int y = y_one; y <= y_two; y++)
				vents[y][x_one]++;

		else if (y_one == y_two)
			for (int x = x_one; x <= x_two; x++)
				vents[y_one][x]++;
	}

	int counter = 0;
	for (int i = 0; i < vents.size(); i++)
		for (int cell = 0; cell < vents[i].size(); cell++)
			if (vents[i][cell] >= 2)
				counter++;

	cout << "Day:  5 | Part: 1 | Result: " << counter << endl;
}

void Day5::part2()
{
	vector<int> x1;
	vector<int> y1;
	vector<int> x2;
	vector<int> y2;

	vector<string> lines;
	Utils::read_lines_from_file("../data/day5.txt", lines);

	vector<string> points, one, two;
	for (string line : lines)
	{
		Utils::split_string(line, " -> ", points);
		Utils::split_string(points[0], ",", one);
		Utils::split_string(points[1], ",", two);

		x1.push_back(stoi(one[0]));
		y1.push_back(stoi(one[1]));
		x2.push_back(stoi(two[0]));
		y2.push_back(stoi(two[1]));
	}

	int max_x = max(
		*max_element(x1.begin(), x1.end()),
		*max_element(x2.begin(), x2.end())
	);
	int max_y = max(
		*max_element(y1.begin(), y1.end()),
		*max_element(y2.begin(), y2.end())
	);

	vector<vector<int>> vents;

	for (int y = 0; y <= max_y; y++)
	{
		vents.push_back(vector<int>());
		for (int x = 0; x <= max_x; x++)
			vents[y].push_back(0);
	}

	for (int index = 0; index < x1.size(); index++)
	{
		int x_one = x1[index];
		int y_one = y1[index];
		int x_two = x2[index];
		int y_two = y2[index];

		if (x_one == x_two)
		{
			if (y_one > y_two) swap(y_one, y_two);
			for (int y = y_one; y <= y_two; y++)
				vents[y][x_one]++;
		}
		else if (y_one == y_two)
		{
			if (x_one > x_two) swap(x_one, x_two);
			for (int x = x_one; x <= x_two; x++)
				vents[y_one][x]++;
		}
		else
		{
			if (x_one > x_two)
			{
				swap(x_one, x_two);
				swap(y_one, y_two);
			}

			for (int o = 0; o <= x_two - x_one; o++)
				vents[y_one < y_two ? y_one + o : y_one - o][x_one + o]++;
		}
	}

	int counter = 0;
	for (int i = 0; i < vents.size(); i++)
		for (int cell = 0; cell < vents[i].size(); cell++)
			if (vents[i][cell] >= 2)
				counter++;

	cout << "Day:  5 | Part: 2 | Result: " << counter << endl;
}