package main

import (
	"aoc2021/Utils"
	"fmt"
)

func Day1_Part1() {
	nums := Utils.ReadFileInts("../data/day1.txt")

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
	nums := Utils.ReadFileInts("../data/day1.txt")

	var last = -1
	var count = 0

	for index := 0; index < len(nums)-2; index++ {
		var sum = nums[index] + nums[index+1] + nums[index+2]

		if last > 0 && sum > last {
			count++
		}

		last = sum
	}

	fmt.Printf("Day:  1 | Part: 2 | Result: %d\n", count)
}
