#include "Day4.h"

bool Day4::testBoardForBingo(std::vector<std::vector<int>> marked)
{
	for (int row_id = 0; row_id < marked.size(); row_id++)
	{
		bool row_true = true, col_true = true;
		for (int cell_id = 0; cell_id < marked[row_id].size(); cell_id++)
		{
			if (!marked[row_id][cell_id])
				row_true = false;

			if (!marked[cell_id][row_id])
				col_true = false;
		}
		if (row_true || col_true)
			return true;
	}

	return false;
}

void Day4::part1()
{
	std::vector<std::string> lines;
	Utils::read_lines_from_file("../data/day4.txt", lines);

	std::vector<std::vector<std::vector<int>>> rows;
	std::vector<std::vector<std::vector<int>>> mark;
	std::vector<int> order;

	std::vector<std::string> order_s;
	Utils::split_string(lines[0], ",", order_s);

	for (std::string num_s : order_s)
		order.push_back(std::stoi(num_s));

	for (int i = 1; i < lines.size(); i++)
	{
		int num_id = 0;

		if (lines[i] == "")
		{
			rows.push_back(std::vector<std::vector<int>>());
			mark.push_back(std::vector<std::vector<int>>());
		}
		else
		{
			rows.back().push_back(std::vector<int>());
			mark.back().push_back(std::vector<int>());

			std::vector<std::string> num_s_v;
			Utils::split_string_regex(lines[i], "([^\\d])", num_s_v);

			for (std::string num_s : num_s_v)
			{
				if (num_s != "")
				{
					rows.back().back().push_back(std::stoi(num_s));
					mark.back().back().push_back(false);
					num_id++;
				}
			}
		}
	}

	int bingo = -1, last_draw = -1;

	for (int draw : order)
	{
		for (int b = 0; b < rows.size(); b++)
			for (int r = 0; r < rows[b].size(); r++)
				for (int n = 0; n < rows[b][r].size(); n++)
					if (rows[b][r][n] == draw)
						mark[b][r][n] = true;

		last_draw = draw;

		for (int index = 0; index < mark.size(); index++)
			if (Day4::testBoardForBingo(mark[index]))
				bingo = index;

		if (bingo != -1)
			break;
	}

	int board_sum = 0;

	for (int r = 0; r < rows[bingo].size(); r++) {
		for (int n = 0; n < rows[bingo][r].size(); n++)
			if (mark[bingo][r][n] == false)
				board_sum += rows[bingo][r][n];
	}

	std::cout << "Day:  4 | Part: 1 | Result: " << board_sum * last_draw << std::endl;
}

void Day4::part2()
{
	std::vector<std::string> lines;
	Utils::read_lines_from_file("../data/day4.txt", lines);

	std::vector<bool> bins;
	std::vector<std::vector<std::vector<int>>> rows;
	std::vector<std::vector<std::vector<int>>> mark;
	std::vector<int> order;

	std::vector<std::string> order_s;
	Utils::split_string(lines[0], ",", order_s);

	for (std::string num_s : order_s)
		order.push_back(std::stoi(num_s));

	for (int i = 1; i < lines.size(); i++)
	{
		if (lines[i] == "")
		{
			bins.push_back(false);
			rows.push_back(std::vector<std::vector<int>>());
			mark.push_back(std::vector<std::vector<int>>());
		}
		else
		{
			rows.back().push_back(std::vector<int>());
			mark.back().push_back(std::vector<int>());

			std::vector<std::string> num_s_v;
			Utils::split_string_regex(lines[i], "([^\\d])", num_s_v);

			for (std::string num_s : num_s_v)
			{
				if (num_s != "")
				{
					rows.back().back().push_back(std::stoi(num_s));
					mark.back().back().push_back(false);
				}
			}
		}
	}

	int bingo = -1, last_draw = -1, bingo_counter = 0;

	for (int draw : order)
	{
		for (int b = 0; b < rows.size(); b++)
			for (int r = 0; r < rows[b].size(); r++)
				for (int n = 0; n < rows[b][r].size(); n++)
					if (rows[b][r][n] == draw)
						mark[b][r][n] = true;

		last_draw = draw;

		for (int index = 0; index < mark.size(); index++)
			if (!bins[index] && Day4::testBoardForBingo(mark[index]))
			{
				bins[index] = true;
				bingo_counter++;
				bingo = index;
			}

		if (bingo_counter == bins.size())
			break;
	}

	int board_sum = 0;

	for (int r = 0; r < rows[bingo].size(); r++)
		for (int n = 0; n < rows[bingo][r].size(); n++)
			if (mark[bingo][r][n] == false)
				board_sum += rows[bingo][r][n];

	std::cout << "Day:  4 | Part: 2 | Result: " << board_sum * last_draw << std::endl;
}