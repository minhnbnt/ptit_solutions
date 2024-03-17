package main

import "fmt"

var strLens = []uint64{0, 1}

func CodeAt(nth uint, index uint64) uint {

	if index < strLens[nth-1] {
		return CodeAt(nth-1, index)
	}

	if index > strLens[nth-1] {
		return CodeAt(nth-1, strLens[nth]-index-1)
	}

	return nth - 1
}

func InitLens(nth uint) {
	for i := len(strLens); uint(i) <= nth; i++ {
		strLens = append(strLens, strLens[i-1]*2+1)
	}
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var nth uint
		var index uint64
		fmt.Scan(&nth, &index)

		InitLens(nth)

		result := 'A' + CodeAt(nth, index-1)
		fmt.Printf("%c\n", result)
	}
}
