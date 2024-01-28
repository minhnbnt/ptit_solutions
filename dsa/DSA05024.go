package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size, target int
		fmt.Scan(&size, &target)

		array := make([]int, size)
		for i := 0; i < size; i++ {
			fmt.Scan(&array[i])
		}

		dp := make([]int, target+1)
		dp[0] = 1
		for i := 1; i <= target; i++ {

			currentTarget := i

			for _, element := range array {

				if currentTarget < element {
					continue
				}

				dp[i] += dp[i-element]
				dp[i] %= int(1e9 + 7)
			}
		}

		fmt.Println(dp[target])
	}
}
