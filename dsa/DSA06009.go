package main

import "fmt"

func CountTwoSum(slice []int, target int) int {

	result := 0
	hashMap := map[int]int{}

	for _, element := range slice {
		result += hashMap[target-element]
		hashMap[element]++
	}

	return result
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size, target int
		fmt.Scan(&size, &target)

		slice := make([]int, size)
		for i := range slice {
			fmt.Scan(&slice[i])
		}

		fmt.Println(CountTwoSum(slice, target))
	}
}
