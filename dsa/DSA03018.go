package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {

	stdin := bufio.NewScanner(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	defer stdout.Flush()

	stdin.Scan()
	cases, _ := strconv.Atoi(stdin.Text())

	for ; cases > 0; cases-- {

		stdin.Scan()
		target, _ := strconv.Atoi(stdin.Text())

		numberOf7, numberOf4 := target/7, -1

		for ; numberOf7 >= 0; numberOf7-- {

			remaining := target - (numberOf7 * 7)

			if remaining%4 == 0 {
				numberOf4 = remaining / 4
				break
			}
		}

		if numberOf4 == -1 {
			stdout.WriteString("-1\n")
			continue
		}

		for ; numberOf4 > 0; numberOf4-- {
			stdout.WriteByte('4')
		}

		for ; numberOf7 > 0; numberOf7-- {
			stdout.WriteByte('7')
		}

		stdout.WriteByte('\n')
	}
}
