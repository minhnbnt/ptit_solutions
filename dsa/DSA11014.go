package main

import "fmt"

type TreeNode struct {
	value       int
	left, right *TreeNode
}

func (self *TreeNode) IsLeaf() bool {

	if self == nil {
		return false
	}

	return self.left == nil && self.right == nil
}

func (self *TreeNode) SumOfRightLeafNode() int {

	if self == nil {
		return 0
	}

	sum := self.left.SumOfRightLeafNode()
	sum += self.right.SumOfRightLeafNode()

	if self.right.IsLeaf() {
		sum += self.right.value
	}

	return sum
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
			fmt.Scan(&parent, &child)

			ptr, has := valueMap[parent]
			if !has {
				root = &TreeNode{value: parent}
				valueMap[parent] = root
				ptr = root
			}

			newNode := &TreeNode{value: child}
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

		fmt.Println(root.SumOfRightLeafNode())
	}
}
