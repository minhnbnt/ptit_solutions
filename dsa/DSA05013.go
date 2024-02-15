package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var distance, speed int
		fmt.Scan(&distance, &speed)

		dp := make([]uint64, distance+1)
		dp[0] = 1

		for i := 1; i <= distance; i++ {
			for j := 1; j <= speed; j++ {

				if i-j < 0 {
					continue
				}

				dp[i] += dp[i-j]
				dp[i] %= uint64(1e9 + 7)
			}
		}

		fmt.Println(dp[distance])
	}
}
