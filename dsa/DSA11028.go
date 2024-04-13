package main

import (
	"container/list"
	"fmt"
)

type TreeNode struct {
	value, depth int
	children     []*TreeNode
}

func (self *TreeNode) GetTheDeepestNode() *TreeNode {

	self.depth = 0

	queue := list.New()
	queue.PushBack(self)

	var result *TreeNode

	for queue.Len() > 0 {

		front := queue.Front()
		current := front.Value.(*TreeNode)

		for _, node := range current.children {
			node.depth = current.depth + 1
			queue.PushBack(node)
		}

		queue.Remove(front)
		result = current
	}

	return result
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var nodes int
		fmt.Scan(&nodes)

		var root *TreeNode
		nodeMap := make(map[int]*TreeNode, nodes)

		for i := 1; i < nodes; i++ {

			var parent, child int
			fmt.Scan(&parent, &child)

			parentPtr, has := nodeMap[parent]

			if !has {
				root = &TreeNode{value: parent}
				nodeMap[parent] = root
				parentPtr = root
			}

			childPtr := &TreeNode{value: child}
			nodeMap[child] = childPtr

			parentPtr.AddChild(childPtr)
		}

		result := root.GetTheDeepestNode()
		fmt.Println(result.depth)
	}
}

func (self *TreeNode) AddChild(child *TreeNode) {
	self.children = append(self.children, child)
}
