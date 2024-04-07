package main

import (
	"fmt"
	"sort"
)

var visited map[int]bool
var adjList map[int][]int

func DFS(start int) {

	if _, has := visited[start]; has {
		return
	}

	fmt.Printf("%d ", start)
	visited[start] = true

	sort.Ints(adjList[start])

	for _, adj := range adjList[start] {
		DFS(adj)
	}
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		visited = map[int]bool{}
		adjList = make(map[int][]int)

		var rank, nEdges, start int
		fmt.Scan(&rank, &nEdges, &start)

		for ; nEdges > 0; nEdges-- {

			var a, b int
			fmt.Scan(&a, &b)

			adjList[a] = append(adjList[a], b)
		}

		DFS(start)
		fmt.Println()
	}
}
