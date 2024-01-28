package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array := make([]int, size)
		for i := 0; i < size; i++ {
			fmt.Scan(&array[i])
		}

		counter := 0
		dp := make([]int, size)

		for i, element := range array {

			dp[i] = 1
			for j := 0; j < i; j++ {
				if array[j] <= element && dp[j] >= dp[i] {
					dp[i] = dp[j] + 1
				}
			}

			if dp[i] > counter {
				counter = dp[i]
			}
		}

		fmt.Println(size - counter)
	}
}
