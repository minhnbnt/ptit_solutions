package main

import (
	"fmt"
	"sort"
)

type TreeNode struct {
	value       int
	left, right *TreeNode
}

func (self *TreeNode) PreorderTransverse() {

	if self == nil {
		return
	}

	fmt.Printf("%d ", self.value)

	self.left.PreorderTransverse()
	self.right.PreorderTransverse()
}

func GetTree(array []int, left int, right int) *TreeNode {

	if left > right {
		return nil
	}

	middle := (left + right) / 2

	root := &TreeNode{value: array[middle]}

	root.left = GetTree(array, left, middle-1)
	root.right = GetTree(array, middle+1, right)

	return root
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

		sort.Ints(array)

		root := GetTree(array, 0, size-1)

		root.PreorderTransverse()
		fmt.Println()
	}
}
