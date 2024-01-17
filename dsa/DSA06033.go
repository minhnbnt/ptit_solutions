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

		slice := make([]ValueIndex, size)
		for i := 0; i < size; i++ {
			fmt.Scan(&slice[i].value)
			slice[i].index = i
		}

		sort.Slice(slice, func(i, j int) bool {

			if slice[i].value != slice[j].value {
				return slice[i].value < slice[j].value
			}

			return slice[i].index < slice[j].index
		})

		j := 0
		longestDistance := -1

		for i := 1; i < size; i++ {

			distance := slice[i].index - slice[j].index
			for ; distance < 0 && i > j; j++ {
				distance = slice[i].index - slice[j].index
			}

			if slice[i].value == slice[j].value {
				continue
			}

			if longestDistance < distance {
				longestDistance = distance
			}
		}

		fmt.Println(longestDistance)
	}
}
