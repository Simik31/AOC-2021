#pragma once
#ifndef DAY_11_H
#define DAY_11_H

#include <iostream>

#include "Utils.h"

class Day11
{
public:
	static void part1();
	static void part2();
private:
	static void flash(vector<vector<pair<int, bool>>>& grid, int x, int y, int& counter);
};

#endif