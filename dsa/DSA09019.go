package main

import "fmt"

var parent map[int]int

func GetParent(a int) int {

	target, isRoot := parent[a]

	if !isRoot {
		return a
	}

	parent[a] = GetParent(target)
	return parent[a]
}

func MergeAndCheck(a, b int) bool {

	aParent := GetParent(a)
	bParent := GetParent(b)

	if aParent == bParent {
		return true
	}

	parent[aParent] = bParent
	return false
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var vertices, edges int
		fmt.Scan(&vertices, &edges)

		hasCycle := false
		parent = make(map[int]int)

		for ; edges > 0; edges-- {

			var a, b int
			fmt.Scan(&a, &b)

			if MergeAndCheck(a, b) {
				hasCycle = true
			}
		}

		if hasCycle {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
