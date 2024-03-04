package main

import (
	"container/ring"
	"fmt"
)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		list := ring.New(size)
		for i := 0; i < size; i++ {

			var element int64
			fmt.Scan(&element)

			list.Value = element
			list = list.Next()
		}

		counter := 0
		for list.Prev().Value.(int64) < list.Value.(int64) {
			list = list.Next()
			counter++
		}

		fmt.Println(counter)
	}
}
