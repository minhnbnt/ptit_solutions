package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array1 := make([]float64, size)
		array2 := make([]float64, size)

		for i := range array1 {
			fmt.Scan(&array1[i], &array2[i])
		}

		result := 0
		dp := make([]int, size)
		for i := range array1 {

			dp[i] = 1

			for j := 0; j < i; j++ {

				if !(array1[i] > array1[j] && array2[i] < array2[j]) {
					continue
				}

				if dp[j] >= dp[i] {
					dp[i] = dp[j] + 1
				}
			}

			if dp[i] > result {
				result = dp[i]
			}
		}

		fmt.Println(result)
	}
}
