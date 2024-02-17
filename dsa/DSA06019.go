package main

import (
	"fmt"
	"sort"
)

type ValueCount struct {
	value   int
	counter int
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var element int
		fmt.Scan(&element)

		counterMap := make(map[int]int)
		for i := 0; i < element; i++ {

			var value int
			fmt.Scan(&value)

			counterMap[value]++
		}

		var counterSlice []ValueCount
		for key, value := range counterMap {
			element := ValueCount{value: key, counter: value}
			counterSlice = append(counterSlice, element)
		}

		sort.Slice(counterSlice, func(i, j int) bool {

			if counterSlice[i].counter != counterSlice[j].counter {
				return counterSlice[i].counter > counterSlice[j].counter
			}

			return counterSlice[i].value < counterSlice[j].value
		})

		for _, valueCounter := range counterSlice {
			for i := 0; i < valueCounter.counter; i++ {
				fmt.Printf("%v ", valueCounter.value)
			}
		}

		fmt.Println()
	}
}
