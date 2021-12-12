package main

import (
	"aoc2021/Utils"
	"fmt"
	"sort"
)

func Day9_Part1() {
	var height_map = make([][]int, 0)
	var lowesr_truths = make([][]bool, 0)

	lines := Utils.ReadFile("../data/day9.txt")

	for line_id := range lines {
		if lines[line_id] != "" {
			height_map = append(height_map, make([]int, 0))
			lowesr_truths = append(lowesr_truths, make([]bool, 0))

			for char_id := range lines[line_id] {
				height_map[len(height_map)-1] = append(height_map[len(height_map)-1], Utils.StrToInt(string(lines[line_id][char_id]), 10))
				lowesr_truths[len(lowesr_truths)-1] = append(lowesr_truths[len(lowesr_truths)-1], false)
			}
		}
	}

	for r := 0; r < len(height_map); r++ {
		for c := 0; c < len(height_map[r]); c++ {
			truths := make([]bool, 0)

			if r >= 1 {
				truths = append(truths, height_map[r][c] < height_map[r-1][c])
			}
			if r+1 < len(height_map) {
				truths = append(truths, height_map[r][c] < height_map[r+1][c])
			}
			if c >= 1 {
				truths = append(truths, height_map[r][c] < height_map[r][c-1])
			}
			if c+1 < len(height_map[r]) {
				truths = append(truths, height_map[r][c] < height_map[r][c+1])
			}

			lowesr_truths[r][c] = !Utils.InArrayBool(truths, false)
		}
	}

	var sum = 0
	for r := 0; r < len(height_map); r++ {
		for c := 0; c < len(height_map[r]); c++ {
			if lowesr_truths[r][c] {
				sum += height_map[r][c] + 1
			}
		}
	}

	fmt.Printf("Day:  9 | Part: 1 | Result: %d\n", sum)
}

func backtrack_basin(height_map *[][]int, r, c, counter int, visited *[]Utils.Pair) int {
	pair := Utils.Pair{First: r, Second: c}
	if Utils.InArrayPair(*visited, pair) {
		return counter
	}

	*visited = append(*visited, pair)
	if (*height_map)[r][c] == 9 {
		return counter
	}

	counter++

	if r >= 1 {
		counter = backtrack_basin(height_map, r-1, c, counter, visited)
	}
	if r+1 < len(*height_map) {
		counter = backtrack_basin(height_map, r+1, c, counter, visited)
	}
	if c >= 1 {
		counter = backtrack_basin(height_map, r, c-1, counter, visited)
	}
	if c+1 < len((*height_map)[r]) {
		counter = backtrack_basin(height_map, r, c+1, counter, visited)
	}

	return counter
}

func Day9_Part2() {
	var height_map = make([][]int, 0)
	var lowesr_truths = make([][]bool, 0)

	lines := Utils.ReadFile("../data/day9.txt")

	for line_id := range lines {
		if lines[line_id] != "" {
			height_map = append(height_map, make([]int, 0))
			lowesr_truths = append(lowesr_truths, make([]bool, 0))

			for char_id := range lines[line_id] {
				height_map[len(height_map)-1] = append(height_map[len(height_map)-1], Utils.StrToInt(string(lines[line_id][char_id]), 10))
				lowesr_truths[len(lowesr_truths)-1] = append(lowesr_truths[len(lowesr_truths)-1], false)
			}
		}
	}

	for r := 0; r < len(height_map); r++ {
		for c := 0; c < len(height_map[r]); c++ {
			truths := make([]bool, 0)

			if r >= 1 {
				truths = append(truths, height_map[r][c] < height_map[r-1][c])
			}
			if r+1 < len(height_map) {
				truths = append(truths, height_map[r][c] < height_map[r+1][c])
			}
			if c >= 1 {
				truths = append(truths, height_map[r][c] < height_map[r][c-1])
			}
			if c+1 < len(height_map[r]) {
				truths = append(truths, height_map[r][c] < height_map[r][c+1])
			}

			lowesr_truths[r][c] = !Utils.InArrayBool(truths, false)
		}
	}

	basins := make([]int, 0)
	visited := make([]Utils.Pair, 0)

	for r := 0; r < len(height_map); r++ {
		for c := 0; c < len(height_map[r]); c++ {
			if lowesr_truths[r][c] {
				basins = append(basins, backtrack_basin(&height_map, r, c, 0, &visited))
			}
		}
	}

	sort.Ints(basins[:])
	var result = basins[len(basins)-1] * basins[len(basins)-2] * basins[len(basins)-3]

	fmt.Printf("Day:  9 | Part: 2 | Result: %d\n", result)
}
