package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var x, y int
		fmt.Scan(&x, &y)

		dp := make([][]uint64, x+1)

		dp[0] = make([]uint64, y+1)
		for j := range dp[0] {
			dp[0][j] = 1
		}

		for i := 1; i <= x; i++ {

			dp[i] = make([]uint64, y+1)
			dp[i][0] = 1

			for j := 1; j <= y; j++ {
				dp[i][j] = dp[i][j-1]
				dp[i][j] += dp[i-1][j]
			}

			dp[i-1] = nil
		}

		fmt.Println(dp[x][y])
	}
}
