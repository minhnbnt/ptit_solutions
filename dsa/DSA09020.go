package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {

	stdin := bufio.NewScanner(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	defer stdout.Flush()

	stdin.Scan()
	line := strings.TrimSpace(stdin.Text())

	rank, _ := strconv.Atoi(line)

	matrix := make([][]bool, rank)
	for i := range matrix {
		matrix[i] = make([]bool, rank)
	}

	for i := 0; i < rank; i++ {

		stdin.Scan()
		line := stdin.Text()

		for _, token := range strings.Fields(line) {

			adjacent, _ := strconv.Atoi(token)
			j := adjacent - 1

			matrix[i][j] = true
			matrix[j][i] = true
		}
	}

	for _, row := range matrix {

		for _, has := range row {
			if has {
				stdout.WriteString("1 ")
			} else {
				stdout.WriteString("0 ")
			}
		}

		stdout.WriteByte('\n')
	}
}
