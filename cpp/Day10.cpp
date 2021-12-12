#include "Day10.h"

void Day10::part1()
{
	vector<char> opens = { '(', '[', '{', '<' };
	vector<char> closes = { ')', ']', '}', '>' };
	map<char, int> incorects = { {')', 0}, {']',  0}, {'}', 0}, {'>', 0 } };

	vector<string> lines;
	Utils::read_lines_from_file("../data/day10.txt", lines);

	for (string line : lines)
	{
		vector<char> pairs;
		for (char c : line)
		{
			if (find(opens.begin(), opens.end(), c) != opens.end())
				pairs.push_back(c);
			else if ((find(opens.begin(), opens.end(), pairs.back()) - opens.begin()) == (find(closes.begin(), closes.end(), c) - closes.begin()))
				pairs.pop_back();
			else
			{
				incorects[c]++;
				break;
			}

		}
	}

	int result = incorects[')'] * 3 + incorects[']'] * 57 + incorects['}'] * 1197 + incorects['>'] * 25137;

	cout << "Day: 10 | Part: 1 | Result: " << result << endl;
}
void Day10::part2()
{
	vector<char> opens = { '(', '[', '{', '<' };
	vector<char> closes = { ')', ']', '}', '>' };
	vector<long long> scores;

	vector<string> lines;
	Utils::read_lines_from_file("../data/day10.txt", lines);

	for (string line : lines)
	{
		vector<char> pairs;
		long long score = 0;
		bool corrupted = false;

		for (char c : line)
		{
			if (find(opens.begin(), opens.end(), c) != opens.end())
				pairs.push_back(c);
			else if ((find(opens.begin(), opens.end(), pairs.back()) - opens.begin()) == (find(closes.begin(), closes.end(), c) - closes.begin()))
				pairs.pop_back();
			else
			{
				corrupted = true;
				break;
			}

		}

		if (!corrupted)
		{
			while (!pairs.empty())
			{
				score = score * 5 + (find(opens.begin(), opens.end(), pairs.back()) - opens.begin()) + 1;
				pairs.pop_back();
			}
			scores.push_back(score);
		}
	}

	sort(scores.begin(), scores.end());
	long long result = scores[scores.size() / 2];

	cout << "Day: 10 | Part: 2 | Result: " << result << endl;
}