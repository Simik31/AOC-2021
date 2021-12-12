package main

import (
	"aoc2021/Utils"
	"fmt"
	"regexp"
	"strings"
)

func test_board_for_bingo(marked [][]bool) bool {
	for row_id := 0; row_id < len(marked); row_id++ {

		var row_true = true
		var col_true = true

		for cell_id := 0; cell_id < len(marked[row_id]); cell_id++ {
			if !marked[row_id][cell_id] {
				row_true = false
			}

			if !marked[cell_id][row_id] {
				col_true = false
			}
		}
		if row_true || col_true {
			return true
		}
	}

	return false
}

func Day4_Part1() {
	lines := Utils.ReadFile("../data/day4.txt")

	rows := make([][][]int, 0)
	mark := make([][][]bool, 0)

	order_s := strings.Split(lines[0], ",")
	var order []int

	for order_id := range order_s {
		order = append(order, Utils.StrToInt(order_s[order_id], 10))
	}

	var board_id = -1
	var line_id = 0

	for i := 1; i < len(lines); i++ {

		if lines[i] == "" {
			board_id++
			line_id = 0

			rows = append(rows, make([][]int, 0))
			mark = append(mark, make([][]bool, 0))
		} else {
			rows[board_id] = append(rows[board_id], make([]int, 0))
			mark[board_id] = append(mark[board_id], make([]bool, 0))

			num_s_v := regexp.MustCompile(`[^\d]`).Split(lines[i], -1)

			for num_s_id := 0; num_s_id < len(num_s_v); num_s_id++ {
				var num_s = num_s_v[num_s_id]
				if num_s != "" {
					rows[board_id][line_id] = append(rows[board_id][line_id], Utils.StrToInt(num_s, 10))
					mark[board_id][line_id] = append(mark[board_id][line_id], false)
				}
			}

			line_id++
		}
	}

	var bingo = -1
	var last_draw = 0

	for draw_id := 0; draw_id < len(order); draw_id++ {
		var draw = order[draw_id]

		for b := 0; b < len(rows); b++ {
			for r := 0; r < len(rows[b]); r++ {
				for n := 0; n < len(rows[b][r]); n++ {
					if rows[b][r][n] == draw {
						mark[b][r][n] = true
					}
				}
			}
		}
		last_draw = draw

		for index := 0; index < len(mark); index++ {
			if test_board_for_bingo(mark[index]) {
				bingo = index
			}
		}

		if bingo != -1 {
			break
		}
	}
	var board_sum = 0

	for r := 0; r < len(rows[bingo]); r++ {
		for n := 0; n < len(rows[bingo][r]); n++ {
			if !mark[bingo][r][n] {
				board_sum += rows[bingo][r][n]
			}
		}
	}

	fmt.Printf("Day:  4 | Part: 1 | Result: %d\n", board_sum*last_draw)
}

func Day4_Part2() {
	lines := Utils.ReadFile("../data/day4.txt")

	bins := make([]bool, 0)
	rows := make([][][]int, 0)
	mark := make([][][]bool, 0)

	order_s := strings.Split(lines[0], ",")
	var order []int

	for order_id := range order_s {
		order = append(order, Utils.StrToInt(order_s[order_id], 10))
	}

	var board_id = -1
	var line_id = 0

	for i := 1; i < len(lines); i++ {

		if lines[i] == "" {
			board_id++
			line_id = 0

			bins = append(bins, false)
			rows = append(rows, make([][]int, 0))
			mark = append(mark, make([][]bool, 0))
		} else {
			rows[board_id] = append(rows[board_id], make([]int, 0))
			mark[board_id] = append(mark[board_id], make([]bool, 0))

			num_s_v := regexp.MustCompile(`[^\d]`).Split(lines[i], -1)

			for num_s_id := 0; num_s_id < len(num_s_v); num_s_id++ {
				var num_s = num_s_v[num_s_id]
				if num_s != "" {
					rows[board_id][line_id] = append(rows[board_id][line_id], Utils.StrToInt(num_s, 10))
					mark[board_id][line_id] = append(mark[board_id][line_id], false)
				}
			}

			line_id++
		}
	}

	var bingo = -1
	var last_draw = 0
	var bingo_count = 0

	for draw_id := 0; draw_id < len(order); draw_id++ {
		var draw = order[draw_id]

		for b := 0; b < len(rows); b++ {
			for r := 0; r < len(rows[b]); r++ {
				for n := 0; n < len(rows[b][r]); n++ {
					if rows[b][r][n] == draw {
						mark[b][r][n] = true
					}
				}
			}
		}
		last_draw = draw

		for index := 0; index < len(mark); index++ {
			if !bins[index] && test_board_for_bingo(mark[index]) {
				bins[index] = true
				bingo = index
				bingo_count += 1
			}
		}

		if bingo_count == len(bins) {
			break
		}
	}
	var board_sum = 0

	for r := 0; r < len(rows[bingo]); r++ {
		for n := 0; n < len(rows[bingo][r]); n++ {
			if !mark[bingo][r][n] {
				board_sum += rows[bingo][r][n]
			}
		}
	}

	fmt.Printf("Day:  4 | Part: 2 | Result: %d\n", board_sum*last_draw)
}
