package main

import (
	"aoc2021/Utils"
	"fmt"
	"strings"
)

func Day5_Part1() {
	lines := Utils.ReadFile("../data/day5.txt")

	x1 := make([]int, 0)
	y1 := make([]int, 0)
	x2 := make([]int, 0)
	y2 := make([]int, 0)

	var max_x int
	var max_y int

	for line_id := range lines {

		points := strings.Split(lines[line_id], " -> ")
		one := strings.Split(points[0], ",")
		two := strings.Split(points[1], ",")

		var x_one = Utils.StrToInt(one[0], 10)
		var y_one = Utils.StrToInt(one[1], 10)
		var x_two = Utils.StrToInt(two[0], 10)
		var y_two = Utils.StrToInt(two[1], 10)

		x1 = append(x1, x_one)
		y1 = append(y1, y_one)
		x2 = append(x2, x_two)
		y2 = append(y2, y_two)

		if x_one > max_x {
			max_x = x_one
		}
		if x_two > max_x {
			max_x = x_two
		}
		if y_one > max_y {
			max_y = y_one
		}
		if y_two > max_y {
			max_y = y_two
		}
	}

	vents := make([][]int, max_y+1)
	for y := 0; y <= max_y; y++ {
		vents[y] = make([]int, max_x+1)
		for x := 0; x <= max_x; x++ {
			vents[y][x] = 0
		}
	}

	for index := 0; index < len(x1); index++ {
		var x_one = x1[index]
		var y_one = y1[index]
		var x_two = x2[index]
		var y_two = y2[index]

		if x_one > x_two {
			x_one, x_two = x_two, x_one
		}
		if y_one > y_two {
			y_one, y_two = y_two, y_one
		}

		if x_one == x_two {
			for y := y_one; y <= y_two; y++ {
				vents[y][x_one]++
			}
		} else if y_one == y_two {
			for x := x_one; x <= x_two; x++ {
				vents[y_one][x]++
			}
		}
	}

	var counter = 0

	for i := 0; i < len(vents); i++ {
		for cell := 0; cell < len(vents[i]); cell++ {
			if vents[i][cell] >= 2 {
				counter++
			}
		}
	}

	fmt.Printf("Day:  5 | Part: 1 | Result: %d\n", counter)
}

func Day5_Part2() {
	lines := Utils.ReadFile("../data/day5.txt")

	x1 := make([]int, 0)
	y1 := make([]int, 0)
	x2 := make([]int, 0)
	y2 := make([]int, 0)

	var max_x int
	var max_y int

	for line_id := range lines {

		points := strings.Split(lines[line_id], " -> ")
		one := strings.Split(points[0], ",")
		two := strings.Split(points[1], ",")

		var x_one = Utils.StrToInt(one[0], 10)
		var y_one = Utils.StrToInt(one[1], 10)
		var x_two = Utils.StrToInt(two[0], 10)
		var y_two = Utils.StrToInt(two[1], 10)

		x1 = append(x1, x_one)
		y1 = append(y1, y_one)
		x2 = append(x2, x_two)
		y2 = append(y2, y_two)

		if x_one > max_x {
			max_x = x_one
		}
		if x_two > max_x {
			max_x = x_two
		}
		if y_one > max_y {
			max_y = y_one
		}
		if y_two > max_y {
			max_y = y_two
		}
	}

	vents := make([][]int, max_y+1)
	for y := 0; y <= max_y; y++ {
		vents[y] = make([]int, max_x+1)
		for x := 0; x <= max_x; x++ {
			vents[y][x] = 0
		}
	}

	for index := 0; index < len(x1); index++ {
		var x_one = x1[index]
		var y_one = y1[index]
		var x_two = x2[index]
		var y_two = y2[index]

		if x_one == x_two {
			if y_one > y_two {
				y_one, y_two = y_two, y_one
			}

			for y := y_one; y <= y_two; y++ {
				vents[y][x_one]++
			}
		} else if y_one == y_two {
			if x_one > x_two {
				x_one, x_two = x_two, x_one
			}

			for x := x_one; x <= x_two; x++ {
				vents[y_one][x]++
			}
		} else {
			if x_one > x_two {
				x_one, x_two = x_two, x_one
				y_one, y_two = y_two, y_one
			}

			var mult = 1
			if y_one > y_two {
				mult = -1
			}

			for o := 0; o <= x_two-x_one; o++ {
				vents[y_one+(o*mult)][x_one+o]++
			}
		}
	}

	var counter = 0

	for i := 0; i < len(vents); i++ {
		for cell := 0; cell < len(vents[i]); cell++ {
			if vents[i][cell] >= 2 {
				counter++
			}
		}
	}

	fmt.Printf("Day:  5 | Part: 1 | Result: %d\n", counter)
}
