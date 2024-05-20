package main

import (
	"container/list"
	"fmt"
	"sort"
)

type AdjList map[int][]int

func (self AdjList) GetPath(from, to int) ([]int, error) {

	queue := list.New()
	queue.PushBack(from)

	parent := map[int]int{
		from: 0,
	}

	for {

		front := queue.Front()

		if front == nil {
			return nil, fmt.Errorf("Can't find path from %d to %d", from, to)
		}

		current := front.Value.(int)
		queue.Remove(front)

		if current == to {
			break
		}

		for _, adj := range self[current] {
			if _, visited := parent[adj]; !visited {
				queue.PushBack(adj)
				parent[adj] = current
			}
		}
	}

	path := []int{}
	for vertex := to; vertex != 0; vertex = parent[vertex] {
		path = append(path, vertex)
	}

	return Reversed(path), nil
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var rank, edges int
		fmt.Scan(&rank, &edges)

		var from, to int
		fmt.Scan(&from, &to)

		graph := make(AdjList)
		for i := 0; i < edges; i++ {

			var u, v int
			fmt.Scan(&u, &v)

			graph.AddEdges(u, v)
		}

		for _, adjs := range graph {
			sort.Ints(adjs)
		}

		path, err := graph.GetPath(from, to)

		if err != nil {
			fmt.Println(-1)
			continue
		}

		for _, vertex := range path {
			fmt.Printf("%d ", vertex)
		}

		fmt.Println()
	}
}

func (self AdjList) AddEdges(from, to int) {
	self[from] = append(self[from], to)
}

func Reversed[T any](array []T) []T {

	left, right := 0, len(array)-1

	for left < right {
		array[left], array[right] = array[right], array[left]
		left, right = left+1, right-1
	}

	return array
}
