#pragma once
#ifndef DAY_9_H
#define DAY_9_H

#include <iostream>

#include "Utils.h"

class Day9
{
public:
	static void part1();
	static void part2();
private:
	static int backtrack_basins(std::vector<std::vector<int>>& height_map, int r, int c, int counter, std::vector<std::pair<int, int>>& visited);
};

#endif