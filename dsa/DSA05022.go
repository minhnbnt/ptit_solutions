package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var length int
		fmt.Scan(&length)

		var insertCost, deleteCost, copyCost int
		fmt.Scan(&insertCost, &deleteCost, &copyCost)

		dp := map[int]int{}
		dp[1] = insertCost

		for i := 2; i <= length; i++ {

			if i%2 == 0 {
				dp[i] = Min(dp[i/2]+copyCost, dp[i-1]+insertCost)
				continue
			}

			dp[i] = Min(dp[i-1]+insertCost, dp[(i+1)/2]+deleteCost+copyCost)
		}

		fmt.Println(dp[length])
	}
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
