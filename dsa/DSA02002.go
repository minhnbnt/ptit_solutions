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
		for i := range array {
			fmt.Scan(&array[i])
		}

		results := make([][]int, 0)

		for {

			results = append(results, array)
			arrayLength := len(array)

			if arrayLength == 1 {
				break
			}

			newArray := make([]int, arrayLength-1)
			for i := range newArray {
				newArray[i] = array[i] + array[i+1]
			}

			array = newArray
		}

		Reverse(results)

		for _, a := range results {
			PrintArray(a)
		}

		fmt.Println()
	}
}

func PrintArray(array []int) {

	endIndex := len(array) - 1

	fmt.Print("[")

	for i, element := range array {

		if i == endIndex {
			fmt.Print(element)
			break
		}

		fmt.Printf("%d ", element)
	}

	fmt.Print("] ")
}

func Reverse[T any](array []T) {

	swapFunc := reflect.Swapper(array)

	left, right := 0, len(array)-1

	for left < right {
		swapFunc(left, right)
		left, right = left+1, right-1
	}
}
