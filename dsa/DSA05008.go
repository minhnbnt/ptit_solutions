package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size, targetSum int
		fmt.Scan(&size, &targetSum)

		array := make([]int, size)
		for i := range array {
			fmt.Scan(&array[i])
		}

		result := false
		dp := make([][]bool, size+1)
		dp[0] = make([]bool, targetSum+1)
		dp[0][0] = true

		for i, element := range array {

			dp[i+1] = make([]bool, targetSum+1)

			for j := 0; j <= targetSum; j++ {

				if dp[i][j] {
					dp[i+1][j] = true
					continue
				}

				sumRemaining := j - element
				if sumRemaining < 0 {
					continue
				}

				dp[i+1][j] = dp[i][sumRemaining]
			}

			if dp[i+1][targetSum] {
				result = true
				break
			}

			dp[i] = nil
		}

		if result {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
