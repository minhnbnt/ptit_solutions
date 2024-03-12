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

		array := make([]bool, size)
		for i := range array {

			var digit int
			fmt.Scan(&digit)

			array[i] = digit != 0
		}

		result := sort.Search(size, func(i int) bool {
			return array[i]
		})

		fmt.Println(result)
	}
}
