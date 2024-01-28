package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var distance, maxStep int
		fmt.Scan(&distance, &maxStep)

		dp := make([]int, distance+1)
		dp[0] = 1

		for i := 1; i <= distance; i++ {
			for j := 1; j <= maxStep; j++ {

				step := j
				distanceRemaining := i - step

				if distanceRemaining < 0 {
					break
				}

				dp[i] += dp[distanceRemaining]
				dp[i] %= int(1e9 + 7)
			}
		}

		fmt.Println(dp[distance])
	}
}
