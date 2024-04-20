package main

import "fmt"

func CanSortChars(s string, distance int) bool {

	charsMap := make(map[rune]int)
	for _, c := range s {
		charsMap[c]++
	}

	maxCount := len(s)/(distance+1) + 1

	for _, counter := range charsMap {
		if counter > maxCount {
			return false
		}
	}

	return true
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var distance int
		fmt.Scan(&distance)

		var str string
		fmt.Scan(&str)

		if CanSortChars(str, distance) {
			fmt.Println(1)
		} else {
			fmt.Println(-1)
		}
	}
}
