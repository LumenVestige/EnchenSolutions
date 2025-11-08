package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func checkTree(root *TreeNode) bool {
	if root.Val == root.Left.Val+root.Right.Val {
		return true
	}
	return false
}

func main() {
	var root TreeNode
	root.Val = 10
	root.Left = &TreeNode{Val: 3}
	root.Right = &TreeNode{Val: 1}
	fmt.Println(checkTree(&root))
}
