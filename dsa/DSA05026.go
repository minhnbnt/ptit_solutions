package main

import "fmt"

func main() {

	var weight, nCows int
	fmt.Scan(&weight, &nCows)

	cows := make([]int, nCows)
	for i := 0; i < nCows; i++ {
		fmt.Scan(&cows[i])
	}

	dp := make([][]int, weight+1)
	dp[0] = make([]int, nCows+1)

	for i := 1; i <= weight; i++ {

		dp[i] = make([]int, nCows+1)

		for j, cowWeight := range cows {

			result := dp[i][j]

			weightRemaining := i - cowWeight
			if weightRemaining < 0 {
				continue
			}

			weightIfTake := dp[weightRemaining][j]
			weightIfTake += cowWeight

			if weightIfTake > result {
				result = weightIfTake
			}

			dp[i][j+1] = result
		}
	}

	fmt.Println(dp[weight][nCows])
}
