#pragma once
#ifndef DAY_4_H
#define DAY_4_H

#include <iostream>
#include <map>

#include "Utils.h"

class Day4
{
public:
	static void part1();
	static void part2();
private:
	static bool testBoardForBingo(vector<vector<int>> marked);
};

#endif