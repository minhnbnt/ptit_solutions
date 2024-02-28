package main

import (
	"fmt"
	"math"
)

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n int
		fmt.Scan(&n)

		dp := make([]int, n+1)
		dp[1] = 1

		for i := 2; i <= n; i++ {

			result := math.MaxInt
			currentNumber := float64(i)

			for j := 1; float64(j) <= math.Sqrt(currentNumber); j++ {
				remaining := i - (j * j)
				result = Min(result, dp[remaining]+1)
			}

			dp[i] = result
		}

		fmt.Println(dp[n])
	}
}
