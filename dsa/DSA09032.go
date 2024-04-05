package main

import "fmt"

var parent map[int]int
var childrenSize map[int]int

func InitDisjointSet(vertices int) {

	childrenSize = make(map[int]int, vertices)
	parent = make(map[int]int, vertices)

	for i := 1; i <= vertices; i++ {
		childrenSize[i] = 1
		parent[i] = i
	}
}

func GetRoot(vertex int) int {

	if parent[vertex] != vertex {
		parent[vertex] = GetRoot(parent[vertex])
	}

	return parent[vertex]
}

func MergeSet(a, b int) {

	aRoot, bRoot := GetRoot(a), GetRoot(b)

	if aRoot == bRoot {
		return
	}

	if childrenSize[aRoot] < childrenSize[bRoot] {
		aRoot, bRoot = bRoot, aRoot
	}

	childrenSize[aRoot] += childrenSize[bRoot]
	parent[bRoot] = aRoot
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var vertices, edges int
		fmt.Scan(&vertices, &edges)

		InitDisjointSet(vertices)

		for ; edges > 0; edges-- {

			var a, b int
			fmt.Scan(&a, &b)

			MergeSet(a, b)
		}

		result := 0
		for _, size := range childrenSize {
			if result < size {
				result = size
			}
		}

		fmt.Println(result)
	}
}
