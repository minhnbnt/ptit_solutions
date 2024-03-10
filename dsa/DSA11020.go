package main

import (
	"fmt"
	"sort"
)

func AreOrdredAndUnique(array []int) bool {

	if !sort.IntsAreSorted(array) {
		return false
	}

	hashSet := map[int]bool{}
	for _, element := range array {

		if _, has := hashSet[element]; has {
			return false
		}

		hashSet[element] = true
	}

	return true
}

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

		if AreOrdredAndUnique(array) {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}
