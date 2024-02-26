package main

import "fmt"

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

		results := [][]int{}

		for {

			results = append(results, array)
			arrayLength := len(array)

			if arrayLength == 1 {
				break
			}

			newArray := []int{}
			for i := 1; i < arrayLength; i++ {
				newArray = append(newArray, array[i]+array[i-1])
			}

			array = newArray
		}

		Reverse(results)

		for _, a := range results {

			endIndex := len(a) - 1

			fmt.Print("[")

			for i, element := range a {

				if i == endIndex {
					fmt.Print(element)
					break
				}

				fmt.Printf("%d ", element)
			}

			fmt.Print("] ")
		}

		fmt.Println()
	}
}

func Reverse[T any](array []T) {

	for i, j := 0, len(array)-1; i < j; {

		array[i], array[j] = array[j], array[i]

		i++
		j--
	}
}
