package main

import "fmt"

func IsCompletedGraph(adjList map[int][]int) bool {

	for vertex, _ := range adjList {
		for _, adj := range adjList[vertex] {
			if len(adjList[vertex]) != len(adjList[adj]) {
				return false
			}
		}
	}

	return true
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var rank, numberOfEdges int
		fmt.Scan(&rank, &numberOfEdges)

		adjList := make(map[int][]int, rank)

		for ; numberOfEdges > 0; numberOfEdges-- {

			var a, b int
			fmt.Scan(&a, &b)

			adjList[a] = append(adjList[a], b)
			adjList[b] = append(adjList[b], a)
		}

		if IsCompletedGraph(adjList) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
