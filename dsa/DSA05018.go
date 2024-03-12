package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var s string
		fmt.Scanln(&s)

		length := len(s)

		dp := make([][]bool, length)
		for i := range dp {
			dp[i] = make([]bool, length)
		}

		result := 0

		for i := range s {

			for j := 0; j < length-i; j++ {

				k := i + j

				if s[j] != s[k] {
					continue
				}

				if !(j+1 > k-1 || dp[j+1][k-1]) {
					continue
				}

				dp[j][k] = true

				if result <= i {
					result = i + 1
				}
			}
		}

		fmt.Println(result)
	}
}
