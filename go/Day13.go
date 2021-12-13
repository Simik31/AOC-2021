package main

import (
	"aoc2021/Utils"
	"fmt"
	"strings"
)

func Day13_Part1() {
	paper := make([][]bool, 0)
	lines := Utils.ReadFile("../data/day13.txt")
	var folding_section_start = 0

	for _, line := range lines {
		folding_section_start++

		if line == "" {
			break
		}

		var x = Utils.StrToInt(strings.Split(line, ",")[0], 10)
		var y = Utils.StrToInt(strings.Split(line, ",")[1], 10)

		for len(paper) <= y {
			paper = append(paper, make([]bool, 0))
		}
		for len(paper[y]) <= x {
			paper[y] = append(paper[y], false)
		}

		paper[y][x] = true
	}

	var longest = 0
	for _, line := range paper {
		if len(line) > longest {
			longest = len(line)
		}
	}

	for line_id := range paper {
		for len(paper[line_id]) < longest {
			paper[line_id] = append(paper[line_id], false)
		}
	}

	var fold_line = lines[folding_section_start]
	var fl_splitted = strings.Split(fold_line, " ")
	var fold_index = Utils.StrToInt(strings.Split(fl_splitted[len(fl_splitted)-1], "=")[1], 10)

	for line := range paper {
		for index := 0; index < longest-fold_index-1; index++ {
			paper[line][index] = paper[line][index] || paper[line][longest-index-1]
		}
		for remove := 0; remove <= fold_index; remove++ {
			paper[line] = Utils.RemoveAtBool(paper[line], fold_index)
		}
	}

	var result = 0
	for _, line := range paper {
		for _, char := range line {
			if char {
				result++
			}
		}
	}

	fmt.Printf("Day: 13 | Part: 1 | Result: %d\n", result)
}

func Day13_Part2() {
	paper := make([][]bool, 0)
	lines := Utils.ReadFile("../data/day13.txt")
	var folding_section_start = 0

	for _, line := range lines {
		folding_section_start++

		if line == "" {
			break
		}

		var x = Utils.StrToInt(strings.Split(line, ",")[0], 10)
		var y = Utils.StrToInt(strings.Split(line, ",")[1], 10)

		for len(paper) <= y {
			paper = append(paper, make([]bool, 0))
		}
		for len(paper[y]) <= x {
			paper[y] = append(paper[y], false)
		}

		paper[y][x] = true
	}

	var longest = 0
	for _, line := range paper {
		if len(line) > longest {
			longest = len(line)
		}
	}

	for line_id := range paper {
		for len(paper[line_id]) < longest {
			paper[line_id] = append(paper[line_id], false)
		}
	}

	for fold_line_id := folding_section_start; fold_line_id < len(lines); fold_line_id++ {
		longest = 0
		for _, line := range paper {
			if len(line) > longest {
				longest = len(line)
			}
		}

		var fl_splitted = strings.Split(lines[fold_line_id], " ")
		var fold_line = fl_splitted[len(fl_splitted)-1]
		var fold_axis = strings.Split(fold_line, "=")[0]
		var fold_index = Utils.StrToInt(strings.Split(fold_line, "=")[1], 10)

		if fold_axis == "x" {
			for line := range paper {
				for index := 0; index < longest-fold_index-1; index++ {
					paper[line][index] = paper[line][index] || paper[line][longest-index-1]
				}
				for remove := 0; remove <= fold_index; remove++ {
					paper[line] = Utils.RemoveAtBool(paper[line], fold_index)
				}
			}
		} else if fold_axis == "y" {
			for line := 0; line < len(paper)-fold_index-1; line++ {
				for index := 0; index < longest; index++ {
					paper[line][index] = paper[line][index] || paper[len(paper)-line-1][index]
				}
			}
			for remove := 0; remove <= fold_index; remove++ {
				paper = Utils.RemoveAtArrayBool(paper, fold_index)
			}
		}
	}

	var result = 0
	for _, line := range paper {
		for _, char := range line {
			if char {
				result++
			}
		}
	}

	fmt.Println("Day: 13 | Part: 1 | Result:")
	for _, line := range paper {
		for _, c := range line {
			var char = " "
			if c {
				char = "#"
			}

			fmt.Printf("%s", char)
		}
		fmt.Println()
	}
}
