package main

import (
	"fmt"
	"sort"
)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var points, edges int
		fmt.Scan(&points, &edges)

		adjList := map[int][]int{}
		for i := 0; i < edges; i++ {

			var a, b int
			fmt.Scan(&a, &b)

			adjList[a] = append(adjList[a], b)
		}

		for i := 1; i <= points; i++ {

			fmt.Printf("%d:", i)

			sort.Ints(adjList[i])
			for _, adj := range adjList[i] {
				fmt.Printf(" %d", adj)
			}

			fmt.Println()
		}
	}
}
