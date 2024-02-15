package main

import (
	"fmt"
	"sort"
)

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size, target int
		fmt.Scan(&size, &target)

		array := make([]int, size)
		for i := range array {
			fmt.Scan(&array[i])
		}

		sort.SliceStable(array, func(i, j int) bool {

			iDiff := Abs(array[i] - target)
			jDiff := Abs(array[j] - target)

			return iDiff < jDiff
		})

		for _, element := range array {
			fmt.Printf("%d ", element)
		}
		fmt.Println()
	}
}
