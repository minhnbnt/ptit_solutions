package main

import "fmt"

func main() {

	var size int
	fmt.Scan(&size)

	slice := make([]int, size)
	for i := range slice {
		fmt.Scan(&slice[i])
	}

	result := 0

	dp := make([]int, size)
	for i, current := range slice {

		resultBefore := 0
		for j := 0; j < i; j++ {
			if slice[j] < current && dp[j] > resultBefore {
				resultBefore = dp[j]
			}
		}

		dp[i] = resultBefore + 1

		if result < dp[i] {
			result = dp[i]
		}
	}

	fmt.Println(result)
}
