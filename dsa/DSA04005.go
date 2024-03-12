package main

import "fmt"

var fibs = []int{0, 1, 1}

func CharAt(nth, index int) string {

	if nth == 1 {
		return "A"
	}

	if nth == 2 {
		return "B"
	}

	if index < fibs[nth-2] {
		return CharAt(nth-2, index)
	} else {
		return CharAt(nth-1, index-fibs[nth-2])
	}
}

func Init(nth int) {

	for {

		fibsLen := len(fibs)

		if fibsLen > nth {
			break
		}

		fibs = append(fibs, fibs[fibsLen-1]+fibs[fibsLen-2])
	}
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var nth, index int
		fmt.Scan(&nth, &index)

		Init(nth)

		fmt.Println(CharAt(nth, index-1))
	}
}
