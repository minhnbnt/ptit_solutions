package main

import (
	"fmt"
	"sort"
)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var vertices, edges int
		fmt.Scan(&vertices, &edges)

		adjList := make(map[int][]int, vertices)
		for i := 0; i < edges; i++ {

			var a, b int
			fmt.Scan(&a, &b)

			adjList[a] = append(adjList[a], b)
			adjList[b] = append(adjList[b], a)
		}

		for i := 1; i <= vertices; i++ {

			fmt.Printf("%d:", i)

			adjs, has := adjList[i]
			if !has {
				fmt.Println()
				continue
			}

			sort.Ints(adjs)
			for _, adj := range adjs {
				fmt.Printf(" %d", adj)
			}
			fmt.Println()
		}
	}
}
