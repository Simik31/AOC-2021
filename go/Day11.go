package main

import (
	"aoc2021/Utils"
	"fmt"
)

func Day11_flash(grid *[][]Utils.PairIntBool, x, y int, counter *int) {
	if (*grid)[y][x].Second {
		return
	}

	(*grid)[y][x].First += 1

	if (*grid)[y][x].First > 9 {
		(*grid)[y][x].First = 0
		(*grid)[y][x].Second = true
		(*counter)++

		for y_off := -1; y_off < 2; y_off++ {
			for x_off := -1; x_off < 2; x_off++ {
				if y+y_off >= 0 && y+y_off < len(*grid) && x+x_off >= 0 && x+x_off < len((*grid)[y+y_off]) {
					Day11_flash(grid, x+x_off, y+y_off, counter)
				}
			}
		}
	}
}

func Day11_Part1() {
	grid := make([][]Utils.PairIntBool, 0)
	lines := Utils.ReadFile("../data/day11.txt")

	for line_id := range lines {
		grid = append(grid, make([]Utils.PairIntBool, 0))
		for char_id := range lines[line_id] {
			grid[len(grid)-1] = append(grid[len(grid)-1], Utils.PairIntBool{First: Utils.StrToInt(string(lines[line_id][char_id]), 10), Second: false})
		}
	}

	var counter = 0
	for step := 0; step < 100; step++ {
		for row_id := 0; row_id < len(grid); row_id++ {
			for col_id := 0; col_id < len(grid[row_id]); col_id++ {
				grid[row_id][col_id].Second = false
			}
		}

		for row_id := 0; row_id < len(grid); row_id++ {
			for col_id := 0; col_id < len(grid[row_id]); col_id++ {
				Day11_flash(&grid, col_id, row_id, &counter)
			}
		}
	}

	fmt.Printf("Day: 11 | Part: 1 | Result: %d\n", counter)
}

func Day11_Part2() {
	grid := make([][]Utils.PairIntBool, 0)
	lines := Utils.ReadFile("../data/day11.txt")

	for line_id := range lines {
		grid = append(grid, make([]Utils.PairIntBool, 0))
		for char_id := range lines[line_id] {
			grid[len(grid)-1] = append(grid[len(grid)-1], Utils.PairIntBool{First: Utils.StrToInt(string(lines[line_id][char_id]), 10), Second: false})
		}
	}

	var counter = 0
	var step = 0
	var all_true = false
	for !all_true {
		step++

		for row_id := 0; row_id < len(grid); row_id++ {
			for col_id := 0; col_id < len(grid[row_id]); col_id++ {
				grid[row_id][col_id].Second = false
			}
		}

		for row_id := 0; row_id < len(grid); row_id++ {
			for col_id := 0; col_id < len(grid[row_id]); col_id++ {
				Day11_flash(&grid, col_id, row_id, &counter)
			}
		}

		all_true = true

		for row_id := 0; all_true && row_id < len(grid); row_id++ {
			for col_id := 0; all_true && col_id < len(grid[row_id]); col_id++ {
				if !grid[row_id][col_id].Second {
					all_true = false
				}
			}
		}
	}

	fmt.Printf("Day: 11 | Part: 2 | Result: %d\n", step)
}
