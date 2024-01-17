package main

import "fmt"

type TreeNode struct {
	value       int
	depth       int
	left, right *TreeNode
}

func NewNode(value int) *TreeNode {
	return &TreeNode{value: value, left: nil, right: nil}
}

func FillDepth(root *TreeNode) int {

	if root == nil {
		return 0
	}

	leftDepth := FillDepth(root.left)
	rightDepth := FillDepth(root.right)

	if leftDepth == -1 || rightDepth == -1 {
		return -1
	}

	if leftDepth != rightDepth {
		return -1
	}

	root.depth = leftDepth + 1
	return root.depth
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var insertAttempt uint
		fmt.Scan(&insertAttempt)

		var root *TreeNode
		valueMap := map[int]*TreeNode{}

		for ; insertAttempt > 0; insertAttempt-- {

			var parent, child int
			fmt.Scan(&parent)
			fmt.Scan(&child)

			ptr, has := valueMap[parent]
			if !has {
				root = NewNode(parent)
				valueMap[parent] = root
				ptr = root
			}

			newNode := NewNode(child)
			valueMap[child] = newNode

			var direction string
			fmt.Scan(&direction)

			switch direction {
			case "L":
				ptr.left = newNode
			case "R":
				ptr.right = newNode
			}
		}

		if FillDepth(root) != -1 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
