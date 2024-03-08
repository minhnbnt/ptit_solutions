package main

import (
	"fmt"
	"sort"
)

func CountThreeSum(array []int, targetSum int) int {

	size := len(array)
	sort.Ints(array)

	result := 0

	for i := range array {

		left, right := i+1, size-1

		for left < right {

			sum := array[i] + array[left] + array[right]

			if sum < targetSum {
				result += right - left
				left++
			} else {
				right--
			}
		}
	}

	return result
}

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

		fmt.Println(CountThreeSum(array, targetSum))
	}
}
