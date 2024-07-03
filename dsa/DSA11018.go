package main

import "fmt"

type TreeNode struct {
	data        int
	left, right *TreeNode
}

func (self *TreeNode) PreorderTransversal() {

	if self == nil {
		return
	}

	fmt.Printf("%v ", self.data)

	self.left.PreorderTransversal()
	self.right.PreorderTransversal()
}

func FillTree(root *TreeNode, node *TreeNode) *TreeNode {

	if root == nil {
		return node
	}

	if node.data < root.data {
		root.left = FillTree(root.left, node)
	} else {
		root.right = FillTree(root.right, node)
	}

	return root
}

func main() {

	var cases int
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		nodes := make([]TreeNode, size)
		for i := range nodes {

			var data int
			fmt.Scan(&data)

			nodes[i] = TreeNode{
				data:  data,
				left:  nil,
				right: nil,
			}
		}

		var root *TreeNode
		for i := range nodes {
			root = FillTree(root, &nodes[i])
		}

		root.PreorderTransversal()
		fmt.Println()
	}
}
