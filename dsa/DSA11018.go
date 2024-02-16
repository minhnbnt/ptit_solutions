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

func FillTree(root **TreeNode, data int) {

	if *root == nil {
		*root = &TreeNode{data: data}
		return
	}

	if data < (*root).data {
		FillTree(&(*root).left, data)
	} else {
		FillTree(&(*root).right, data)
	}
}

func GetTreeByLevelOrder(levelOrder []int) *TreeNode {

	length := len(levelOrder)
	if length == 0 {
		return nil
	}

	root := &TreeNode{data: levelOrder[0]}

	for i := 1; i < length; i++ {
		FillTree(&root, levelOrder[i])
	}

	return root
}

func main() {

	var cases int
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		levelOrder := make([]int, size)
		for i := range levelOrder {
			fmt.Scan(&levelOrder[i])
		}

		root := GetTreeByLevelOrder(levelOrder)

		root.PreorderTransversal()
		fmt.Println()
	}
}
