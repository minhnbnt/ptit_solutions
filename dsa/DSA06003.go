package main

import (
	"fmt"
	"reflect"
)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array := make([]int, size)
		swapFunc := reflect.Swapper(array)

		for i := range array {
			fmt.Scan(&array[i])
		}

		result := 0

		for i := range array {

			target := i

			for j := i; j < size; j++ {
				if array[j] < array[target] {
					target = j
				}
			}

			if target == i {
				continue
			}

			swapFunc(i, target)
			result += 1
		}

		fmt.Println(result)
	}
}
