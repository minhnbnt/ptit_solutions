package main

import (
	"fmt"
	"sort"
)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var element int
		fmt.Scan(&element)

		slice := make([]int, element)
		for i := 0; i < element; i++ {
			fmt.Scan(&slice[i])
		}

		sorted := make([]int, element)
		copy(sorted, slice)
		sort.Ints(sorted)

		left, right := 0, element-1

		for slice[left] == sorted[left] {
			left++
		}

		for slice[right] == sorted[right] {
			right--
		}

		fmt.Println(left+1, right+1)
	}
}
