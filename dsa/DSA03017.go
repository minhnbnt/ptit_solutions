package main

import (
	"fmt"
	"sort"
)

func MinimumValue(s string, removeAttempt uint) uint64 {

	charsCounter := make(map[rune]int)
	for _, c := range s {
		charsCounter[c]++
	}

	var values []int
	for _, counter := range charsCounter {
		values = append(values, counter)
	}

	sort.Ints(values)
	for removeAttempt > 0 {

		size := len(values)

		lastElement := values[size-1]
		startIndex := sort.SearchInts(values, lastElement)

		for i := startIndex; i < size; i++ {

			removeAttempt -= 1
			values[i] -= 1

			if removeAttempt == 0 {
				break
			}
		}
	}

	result := uint64(0)
	for _, x := range values {
		element := uint64(x)
		result += element * element
	}

	return result
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var str string
		var removeAttempt uint
		fmt.Scan(&removeAttempt, &str)

		result := MinimumValue(str, removeAttempt)
		fmt.Println(result)
	}
}
