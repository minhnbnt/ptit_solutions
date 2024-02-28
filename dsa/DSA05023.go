package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n uint64
		fmt.Scan(&n)

		result := uint64(0)
		for ; n > 0; n /= 10 {

			mod := uint64(10)

			for {

				add := n % mod
				result += add

				mod *= 10

				if add == n {
					break
				}
			}
		}

		fmt.Println(result)
	}
}
