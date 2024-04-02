package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {

	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	defer stdout.Flush()

	line, _ := stdin.ReadString('\n')
	rank, _ := strconv.Atoi(strings.TrimSpace(line))

	matrix := make([][]bool, rank)
	for i := range matrix {
		matrix[i] = make([]bool, rank)
	}

	for i := 0; i < rank; i++ {

		line, _ = stdin.ReadString('\n')

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
