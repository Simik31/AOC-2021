package main

import (
	"aoc2021/utils"
	"fmt"
	"strings"
)

func Day2_Part1() {
	input := utils.ReadFile("../data/day2.txt")

	var h_pos = 0
	var v_pos = 0

	for row := range input {
		parts := strings.Fields(input[row])

		value := utils.StrToInt(parts[1], 10)
		switch parts[0] {
		case "forward":
			h_pos += value
		case "down":
			v_pos += value
		case "up":
			v_pos -= value
		default:
			panic("Unknown command: " + parts[0])
		}
	}

	fmt.Printf("Day:  2 | Part: 1 | Result: %d\n", h_pos*v_pos)
}

func Day2_Part2() {
	input := utils.ReadFile("../data/day2.txt")

	var h_pos = 0
	var v_pos = 0
	var aim = 0

	for row := range input {
		parts := strings.Fields(input[row])

		value := utils.StrToInt(parts[1], 10)
		switch parts[0] {
		case "forward":
			h_pos += value
			v_pos += aim * value
		case "down":
			aim += value
		case "up":
			aim -= value
		default:
			panic("Unknown command: " + parts[0])
		}
	}

	fmt.Printf("Day:  2 | Part: 2 | Result: %d\n", h_pos*v_pos)
}
