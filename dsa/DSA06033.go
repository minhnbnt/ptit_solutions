package main

import (
	"fmt"
	"sort"
)

type ValueIndex struct {
	index, value int
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array := make([]ValueIndex, size)
		for i := range array {
			fmt.Scan(&array[i].value)
			array[i].index = i
		}

		sort.Slice(array, func(i, j int) bool {

			if array[i].value != array[j].value {
				return array[i].value < array[j].value
			}

			return array[i].index < array[j].index
		})

		j := 0
		longestDistance := -1

		for i := 1; i < size; i++ {

			var distance int

			for ; j < i; j++ {

				distance = array[i].index - array[j].index

				if distance > 0 {
					break
				}
			}

			if array[i].value == array[j].value {
				continue
			}

			if longestDistance < distance {
				longestDistance = distance
			}
		}

		fmt.Println(longestDistance)
	}
}
