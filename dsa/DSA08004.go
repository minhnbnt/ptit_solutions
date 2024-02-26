package main

import (
	"container/heap"
	"fmt"
)

type IntHeap struct {
	array []int
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var removeAttempt uint
		fmt.Scan(&removeAttempt)

		var str string
		fmt.Scan(&str)

		charsMap := map[rune]int{}
		for _, c := range str {
			charsMap[c]++
		}

		values := IntHeap{}
		for _, counter := range charsMap {
			values.Push(counter)
		}

		heap.Init(&values)
		for ; removeAttempt > 0; removeAttempt-- {

			target := heap.Pop(&values).(int)
			target -= 1

			heap.Push(&values, target)
		}

		result := uint64(0)
		for _, x := range values.array {
			element := uint64(x)
			result += element * element
		}

		fmt.Println(result)
	}
}

// Some methods to make Priority queue works
// https://go.dev/src/container/heap/example_intheap_test.go
func (self *IntHeap) Less(i, j int) bool { return self.array[i] > self.array[j] }
func (self *IntHeap) Len() int           { return len(self.array) }

func (self *IntHeap) Swap(i, j int) {
	self.array[i], self.array[j] = self.array[j], self.array[i]
}

func (self *IntHeap) Push(x any) {
	self.array = append(self.array, x.(int))
}

func (self *IntHeap) Pop() any {

	size := self.Len()

	element := self.array[size-1]
	self.array = self.array[:size-1]

	return element
}
