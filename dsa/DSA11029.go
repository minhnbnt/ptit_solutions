package main

import (
	"fmt"
	"sort"
)

type TreeNode struct {
	value    int
	parent   *TreeNode
	children []*TreeNode
}

func WayFromRoot(node *TreeNode) {

	if node == nil {
		return
	}

	WayFromRoot(node.parent)

	fmt.Printf("%v ", node.value)
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var numberOfNode int
		fmt.Scan(&numberOfNode)

		nodeMap := map[int]*TreeNode{}
		for i := 1; i < numberOfNode; i++ {

			var parent, child int
			fmt.Scan(&parent, &child)

			parentPtr, has := nodeMap[parent]
			if !has {
				root := &TreeNode{value: parent}

				nodeMap[parent] = root
				parentPtr = root
			}

			childPtr := &TreeNode{value: child, parent: parentPtr}
			nodeMap[child] = childPtr

			parentPtr.children = append(parentPtr.children, childPtr)
		}

		leapNodes := []*TreeNode{}
		for _, node := range nodeMap {

			if len(node.children) != 0 {
				continue
			}

			leapNodes = append(leapNodes, node)
		}

		sort.Slice(leapNodes, func(i, j int) bool {
			return leapNodes[i].value < leapNodes[j].value
		})

		for _, node := range leapNodes {
			WayFromRoot(node)
			fmt.Println()
		}
	}
}
