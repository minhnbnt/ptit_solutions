package main

import "fmt"

func main() {

	var weight, nCows int
	fmt.Scan(&weight, &nCows)

	cows := make([]int, nCows)
	for i := range cows {
		fmt.Scan(&cows[i])
	}

	dp := make([][]int, nCows+1)
	dp[0] = make([]int, weight+1)

	for i := 1; i <= nCows; i++ {

		currentCow := cows[i-1]
		dp[i] = make([]int, weight+1)

		for j := 1; j <= weight; j++ {

			result := dp[i-1][j]

			weightRemaining := j - currentCow
			if weightRemaining < 0 {
				continue
			}

			weightIfTake := dp[i-1][weightRemaining] + currentCow
			if weightIfTake > result {
				result = weightIfTake
			}

			dp[i][j] = result
		}

		dp[i-1] = nil
	}

	fmt.Println(dp[nCows][weight])
}
