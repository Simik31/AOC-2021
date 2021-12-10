package main

import (
	"aoc2021/utils"
	"fmt"
	"math"
	"strings"
)

func Day7_Part1() {
	nums_s := strings.Split(utils.ReadFile("../data/day7.txt")[0], ",")
	positions := make([]int, 0)

	for nums_id := range nums_s {
		positions = append(positions, utils.StrToInt(nums_s[nums_id], 10))
	}

	var min_cost = int(^uint(0) >> 1)

	for position_end_id := range positions {
		var position_cost = 0

		for position_crab_id := range positions {
			position_cost += int(math.Abs(float64(positions[position_end_id] - positions[position_crab_id])))
		}

		if position_cost < min_cost {
			min_cost = position_cost
		}
	}

	fmt.Printf("Day:  7 | Part: 1 | Result: %d\n", min_cost)
}

func Day7_Part2() {
	nums_s := strings.Split(utils.ReadFile("../data/day7.txt")[0], ",")
	positions := make([]int, 0)
	var max_position = 0

	for nums_id := range nums_s {
		position := utils.StrToInt(nums_s[nums_id], 10)
		positions = append(positions, position)

		if position > max_position {
			max_position = position
		}
	}

	var min_cost = int(^uint(0) >> 1)

	for position_end := 0; position_end < max_position; position_end++ {
		var position_cost = 0

		for position_crab_id := range positions {
			for step := 1; step <= int(math.Abs(float64(position_end-positions[position_crab_id]))); step++ {
				position_cost += step
			}
		}

		if position_cost < min_cost {
			min_cost = position_cost
		}
	}

	fmt.Printf("Day:  7 | Part: 2 | Result: %d\n", min_cost)
}
