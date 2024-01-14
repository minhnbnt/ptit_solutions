package main

import (
	"fmt"
	"sort"
)

type ValueCount struct {
	value   int
	counter uint
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var element int
		fmt.Scan(&element)

		counterMap := make(map[int]uint)
		for i := 0; i < element; i++ {

			var value int
			fmt.Scan(&value)

			counterMap[value]++
		}

		var counterSlice []ValueCount
		for key, value := range counterMap {
			append(counterSlice, ValueCount{value: key, counter: value})
		}

	}
}
