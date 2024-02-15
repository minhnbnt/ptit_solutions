package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array := make([]int, size)
		for i := range array {
			fmt.Scan(&array[i])
		}

		dp := make([]int, size)
		for i, element := range array {

			ifContainI := 0

			for j := 0; j < i; j++ {
				if ifContainI < dp[j] && element > array[j] {
					ifContainI = dp[j]
				}
			}

			dp[i] = ifContainI + element
		}

		result := 0
		for _, element := range dp {
			if element > result {
				result = element
			}
		}

		fmt.Println(result)
	}
}
