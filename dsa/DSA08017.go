package main

import (
	"container/list"
	"fmt"
	"strings"
)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		queue := list.New()
		queue.PushBack("6")
		queue.PushBack("8")

		for ptr := queue.Front(); len(ptr.Value.(string)) < size; ptr = ptr.Next() {

			for _, char := range []rune{'6', '8'} {

				var builder strings.Builder
				fmt.Fprintf(&builder, "%s%c", ptr.Value, char)

				queue.PushBack(builder.String())
			}
		}

		for ptr := queue.Back(); ptr != nil; ptr = ptr.Prev() {
			fmt.Printf("%s ", ptr.Value)
		}

		fmt.Println()
	}
}
