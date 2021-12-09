package main

import (
	"aoc2021/utils"
	"fmt"
)

func Day1_Part1() {
	nums := utils.ReadFileInts("../data/day1.txt")

	var last = -1
	var count = 0

	for num := range nums {
		if last > 0 && nums[num] > last {
			count++
		}
		last = nums[num]
	}

	fmt.Printf("Day:  1 | Part: 1 | Result: %d\n", count)
}

func Day1_Part2() {
	nums := utils.ReadFileInts("../data/day1.txt")
	sums := make([]int, len(nums))

	for index := 0; index < len(nums)-2; index++ {
		for offset := 0; offset < 3; offset++ {
			sums[index] += nums[index+offset]
		}
	}

	var last = -1
	var count = 0

	for sum := range sums {
		if last > 0 && sums[sum] > last {
			count++
		}
		last = sums[sum]
	}

	fmt.Printf("Day:  1 | Part: 2 | Result: %d\n", count)
}
