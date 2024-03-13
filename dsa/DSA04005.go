package main

import "fmt"

var fibs = []uint64{0, 1, 1}

func CharAt(nth uint, index uint64) byte {

	if nth == 1 {
		return 'A'
	}

	if nth == 2 {
		return 'B'
	}

	if index < fibs[nth-2] {
		return CharAt(nth-2, index)
	} else {
		return CharAt(nth-1, index-fibs[nth-2])
	}
}

func InitFibs(nth uint) {
	for i := len(fibs); uint(i) < nth; i++ {
		fibs = append(fibs, fibs[i-1]+fibs[i-2])
	}
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var nth uint
		var index uint64
		fmt.Scan(&nth, &index)

		InitFibs(nth)

		fmt.Printf("%c\n", CharAt(nth, index-1))
	}
}
