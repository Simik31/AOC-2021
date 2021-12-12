package main

import (
	"aoc2021/Utils"
	"fmt"
	"sort"
)

func Day10_Part1() {
	var opens = []string{"(", "[", "{", "<"}
	var closes = []string{")", "]", "}", ">"}
	incorects := map[string]int{")": 0, "]": 0, "}": 0, ">": 0}

	lines := Utils.ReadFile("../data/day10.txt")

	for line_id := range lines {
		pairs := make([]string, 0)
		for char_id := range lines[line_id] {
			if Utils.InArrayString(opens, string(lines[line_id][char_id])) {
				pairs = append(pairs, string(lines[line_id][char_id]))
			} else if Utils.IndexOf(opens, pairs[len(pairs)-1]) == Utils.IndexOf(closes, string(lines[line_id][char_id])) {
				pairs = append(pairs[:(len(pairs)-1)], pairs[len(pairs):]...)
			} else {
				incorects[string(lines[line_id][char_id])]++
				break
			}
		}
	}

	var result int = incorects[")"]*3 + incorects["]"]*57 + incorects["}"]*1197 + incorects[">"]*25137

	fmt.Printf("Day: 10 | Part: 1 | Result: %d\n", result)
}

func Day10_Part2() {
	var opens = []string{"(", "[", "{", "<"}
	var closes = []string{")", "]", "}", ">"}
	costs := make([]int, 0)

	lines := Utils.ReadFile("../data/day10.txt")

	for line_id := range lines {
		pairs := make([]string, 0)
		var cost int = 0
		var corrupted bool = false

		for char_id := range lines[line_id] {
			if Utils.InArrayString(opens, string(lines[line_id][char_id])) {
				pairs = append(pairs, string(lines[line_id][char_id]))
			} else if Utils.IndexOf(opens, pairs[len(pairs)-1]) == Utils.IndexOf(closes, string(lines[line_id][char_id])) {
				pairs = Utils.RemoveAt(pairs, len(pairs)-1)
			} else {
				corrupted = true
				break
			}
		}

		if !corrupted {
			for len(pairs) > 0 {
				cost = cost*5 + Utils.IndexOf(opens, pairs[len(pairs)-1]) + 1
				pairs = Utils.RemoveAt(pairs, len(pairs)-1)
			}
			costs = append(costs, cost)
		}
	}

	sort.Ints(costs[:])
	var result int = costs[len(costs)/2]

	fmt.Printf("Day: 10 | Part: 2 | Result: %d\n", result)
}
