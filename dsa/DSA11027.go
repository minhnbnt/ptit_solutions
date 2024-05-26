package main

import "fmt"

type TreeNode struct {
	value       int
	left, right *TreeNode
}

func GetAVLTree(sorted []int, left, right int) *TreeNode {

	if left > right {
		return nil
	}

	middle := (left + right - 1) / 2

	return &TreeNode{
		value: sorted[middle],
		left:  GetAVLTree(sorted, left, middle),
		right: GetAVLTree(sorted, middle+1, right),
	}
}

func (root *TreeNode) CountLeaves() int {

	if root == nil {
		return 0
	}

	result := root.left.CountLeaves()
	result += root.right.CountLeaves()

	if root.left == nil && root.right == nil {
		result += 1
	}

	return result
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array := make([]int, size)
		for i := range array {
			fmt.Scan(&array[i])
		}

		root := GetAVLTree(array, 0, size)
		fmt.Println(root.CountLeaves())
	}
}
