package main

import (
	"fmt"
	"sort"
)

func threeSum(slice []int, target int) bool {

	sort.Ints(slice)

	size := len(slice)
	for i := 2; i < size; i++ {

		left, right := 0, i-1
		for left < right {

			sum := slice[i] + slice[left] + slice[right]

			if sum == target {
				return true
			} else if sum < target {
				left++
			} else {
				right--
			}
		}
	}

	return false
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size, target int
		fmt.Scan(&size, &target)

		slice := make([]int, size)
		for i := 0; i < size; i++ {
			fmt.Scan(&slice[i])
		}

		if threeSum(slice, target) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
