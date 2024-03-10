package main

import (
	"fmt"
	"sort"
)

type TreeNode struct {
	value       int
	left, right *TreeNode
}

func (self *TreeNode) InorderTransversal() {

	if self == nil {
		return
	}

	self.left.InorderTransversal()

	fmt.Printf("%d ", self.value)

	self.right.InorderTransversal()
}

func AssignIndex(root *TreeNode, indexMap map[int]*TreeNode) {

	if root == nil {
		return
	}

	AssignIndex(root.left, indexMap)

	indexMap[len(indexMap)] = root

	AssignIndex(root.right, indexMap)
}

func BuildTree() *TreeNode {

	var insertAttempt int
	fmt.Scan(&insertAttempt)

	root := (*TreeNode)(nil)
	nodeMap := map[int]*TreeNode{}

	for ; insertAttempt > 0; insertAttempt-- {

		var direction string
		var parent, child int
		fmt.Scan(&parent, &child, &direction)

		parentPtr, has := nodeMap[parent]
		if !has {
			root = &TreeNode{value: parent}
			nodeMap[parent] = root
			parentPtr = root
		}

		childPtr := &TreeNode{value: child}
		nodeMap[child] = childPtr

		switch direction {
		case "L":
			parentPtr.left = childPtr
		case "R":
			parentPtr.right = childPtr
		}
	}

	return root
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		root := BuildTree()

		indexMap := map[int]*TreeNode{}
		AssignIndex(root, indexMap)

		values := make([]int, 0)
		for _, ptr := range indexMap {
			values = append(values, ptr.value)
		}

		sort.Ints(values)
		for i, element := range values {
			indexMap[i].value = element
		}

		root.InorderTransversal()
		fmt.Println()
	}
}
