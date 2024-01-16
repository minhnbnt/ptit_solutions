package main

import (
	"fmt"
	"sort"
)

const MOD = int64(1e9 + 7)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		slice := make([]int, size)
		for i := 0; i < size; i++ {
			fmt.Scan(&slice[i])
		}

		sort.Ints(slice)

		var result int64 = 0
		for i, element := range slice {
			result += int64(element) * int64(i)
			result %= MOD
		}

		fmt.Println(result)
	}
}
