package main

import (
	"aoc2021/Utils"
	"fmt"
)

func Day3_Part1() {
	data := Utils.ReadFile("../data/day3.txt")

	var gama = 0
	var epsilon = 0

	for i := 0; i < len(data[0]); i++ {
		var counter = []int{0, 0}

		for r := range data {
			counter[Utils.StrToInt8(string(data[r][i]), 10)]++
		}

		var g int
		var e int

		if counter[0] > counter[1] {
			g, e = 0, 1
		} else {
			g, e = 1, 0
		}

		gama = (gama << 1) + g
		epsilon = (epsilon << 1) + e
	}

	fmt.Printf("Day:  3 | Part: 1 | Result: %d\n", (gama * epsilon))
}

func Day3_Part2() {
	data_og := Utils.ReadFile("../data/day3.txt")
	data_co2s := data_og

	for i := 0; i < len(data_og[0]); i++ {
		if len(data_og) > 1 {
			var counter = []int{0, 0}

			for r := range data_og {
				counter[Utils.StrToInt8(string(data_og[r][i]), 10)]++
			}

			var b byte

			if counter[1] >= counter[0] {
				b = '1'
			} else {
				b = '0'
			}

			tmp := make([]string, 0)
			for r := range data_og {
				if data_og[r][i] == b {
					tmp = append(tmp, data_og[r])
				}
			}

			data_og = tmp
		}

		if len(data_co2s) > 1 {
			var counter = []int{0, 0}

			for r := range data_co2s {
				counter[Utils.StrToInt8(string(data_co2s[r][i]), 10)]++
			}

			var b byte

			if counter[1] >= counter[0] {
				b = '0'
			} else {
				b = '1'
			}

			var tmp []string
			for r := range data_co2s {
				if data_co2s[r][i] == b {
					tmp = append(tmp, data_co2s[r])
				}
			}

			data_co2s = tmp
		}

		if len(data_og) == 1 && len(data_co2s) == 1 {
			break
		}

	}

	fmt.Printf("Day:  3 | Part: 2 | Result: %d\n", Utils.StrToInt64(data_og[0], 2)*Utils.StrToInt64(data_co2s[0], 2))
}
