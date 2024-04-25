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

func (self *TreeNode) SumOfRightLeaves() int {

	if self == nil {
		return 0
	}

	sum := self.left.SumOfRightLeaves()
	sum += self.right.SumOfRightLeaves()

	if right := self.right; right.IsLeaf() {
		sum += right.value
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
		nodesMap := make(map[int]*TreeNode)

		for ; insertAttempt > 0; insertAttempt-- {

			var parent, child int
			fmt.Scan(&parent, &child)

			if root == nil {
				root = &TreeNode{value: parent}
				nodesMap[parent] = root
			}

			var direction string
			fmt.Scan(&direction)

			/* for some reason, finding parent node
			   after creating child node give us WA :0 */
			parentNode := nodesMap[parent]

			childNode := &TreeNode{value: child}
			nodesMap[child] = childNode

			switch direction {
			case "L":
				parentNode.left = childNode
			case "R":
				parentNode.right = childNode
			}
		}

		fmt.Println(root.SumOfRightLeaves())
	}
}
