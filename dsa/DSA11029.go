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

func (self *TreeNode) PathFromRoot() []int {

	if self == nil {
		return nil
	}

	path := self.parent.PathFromRoot()
	return append(path, self.value)
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var numberOfNode int
		fmt.Scan(&numberOfNode)

		nodeMap := make(map[int]*TreeNode)
		for i := 1; i < numberOfNode; i++ {

			var parent, child int
			fmt.Scan(&parent, &child)

			parentPtr, has := nodeMap[parent]
			if !has {
				root := &TreeNode{value: parent}
				nodeMap[parent] = root
				parentPtr = root
			}

			childPtr := &TreeNode{
				parent: parentPtr,
				value:  child,
			}

			nodeMap[child] = childPtr

			parentPtr.children = append(parentPtr.children, childPtr)
		}

		leafNodes := []*TreeNode{}
		for _, node := range nodeMap {
			if len(node.children) == 0 {
				leafNodes = append(leafNodes, node)
			}
		}

		sort.Slice(leafNodes, func(i, j int) bool {
			return leafNodes[i].value < leafNodes[j].value
		})

		for _, node := range leafNodes {

			for _, value := range node.PathFromRoot() {
				fmt.Printf("%v ", value)
			}

			fmt.Println()
		}
	}
}
