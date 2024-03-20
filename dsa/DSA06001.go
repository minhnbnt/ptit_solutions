package main

import (
	"fmt"
	"sort"
)

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

		sort.Ints(array)

		left, right := 0, size-1

		for i := 0; left <= right; i++ {

			if i%2 == 0 {
				fmt.Printf("%d ", array[right])
				right--
			} else {
				fmt.Printf("%d ", array[left])
				left++
			}
		}

		fmt.Println()
	}
}
