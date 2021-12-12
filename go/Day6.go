package main

import (
	"aoc2021/Utils"
	"fmt"
	"strings"
)

func Day6_Part1() {
	nums_s := strings.Split(Utils.ReadFile("../data/day6.txt")[0], ",")
	ages := make(map[int]int, 0)

	for age := -1; age < 9; age++ {
		ages[age] = 0
	}

	for nums_id := range nums_s {
		ages[Utils.StrToInt(nums_s[nums_id], 10)]++
	}

	for day := 0; day < 80; day++ {
		for age := -1; age < 8; age++ {
			ages[age] = ages[age+1]
		}
		ages[6] += ages[-1]
		ages[8] = ages[-1]
	}

	var result = 0
	for age := 0; age < 9; age++ {
		result += ages[age]
	}

	fmt.Printf("Day:  6 | Part: 1 | Result: %d\n", result)
}

func Day6_Part2() {
	nums_s := strings.Split(Utils.ReadFile("../data/day6.txt")[0], ",")
	ages := make(map[int]int, 0)

	for age := -1; age < 9; age++ {
		ages[age] = 0
	}

	for nums_id := range nums_s {
		ages[Utils.StrToInt(nums_s[nums_id], 10)]++
	}

	for day := 0; day < 256; day++ {
		for age := -1; age < 8; age++ {
			ages[age] = ages[age+1]
		}
		ages[6] += ages[-1]
		ages[8] = ages[-1]
	}

	var result = 0
	for age := 0; age < 9; age++ {
		result += ages[age]
	}

	fmt.Printf("Day:  6 | Part: 2 | Result: %d\n", result)
}
