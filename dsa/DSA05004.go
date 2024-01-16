package main

import "fmt"

func main() {

	var size int
	fmt.Scan(&size)

	slice := make([]int, size)
	for i := 0; i < size; i++ {
		fmt.Scan(&slice[i])
	}

	dp := make([]int, size)
	for i, current := range slice {

		resultBefore := 0
		for j := 0; j < i; j++ {
			if slice[j] < current && dp[j] > resultBefore {
				resultBefore = dp[j]
			}
		}

		dp[i] = resultBefore + 1
	}

	result := 0
	for _, x := range dp {
		if result < x {
			result = x
		}
	}

	fmt.Println(result)
}
