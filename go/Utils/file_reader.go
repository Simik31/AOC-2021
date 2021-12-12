package Utils

import (
	"bufio"
	"io"
	"os"
	"strconv"
	"strings"
)

func ReadFile(filename string) []string {
	file, err := os.Open(filename)

	if err != nil {
		panic(err)
	}

	defer file.Close()

	reader := bufio.NewReader(file)
	lines := make([]string, 0)
	var line string

	for {
		line, err = reader.ReadString('\n')

		if line == "" || (err != nil && err != io.EOF) {
			break
		}

		lines = append(lines, strings.Trim(line, "\r\n"))
	}

	return lines
}

func ReadFileInts(filename string) []int {
	lines := ReadFile(filename)

	nums := make([]int, 0, len(lines))

	for line := range lines {
		num, err := strconv.Atoi(lines[line])

		if err != nil {
			panic(err)
		}

		nums = append(nums, num)
	}

	return nums
}
