package main

import "fmt"

type TreeNode struct {
	value       int
	left, right *TreeNode
}

func (self *TreeNode) IsEqual(other *TreeNode) bool {

	if self == nil && other == nil {
		return true
	}

	if self == nil || other == nil {
		return false
	}

	if self.value != other.value {
		return false
	}

	if !self.left.IsEqual(other.left) {
		return false
	}

	if !self.right.IsEqual(other.right) {
		return false
	}

	return true
}

func BuildTree() *TreeNode {

	var insertAttempt int
	fmt.Scan(&insertAttempt)

	var root *TreeNode
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

		root1 := BuildTree()
		root2 := BuildTree()

		if root1.IsEqual(root2) {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}
