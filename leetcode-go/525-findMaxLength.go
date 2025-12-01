package main

import "fmt"

func findMaxLength(nums []int) int {
	// 构建前缀和
	pos := map[int]int{0: -1}
	var diff, ans int
	// 遍历右 维护左
	for i := range nums {
		if nums[i] == 0 {
			nums[i] = -1
		}
		diff += nums[i]
		if j, ok := pos[diff]; ok {
			ans = max(ans, i-j)
		} else {
			pos[diff] = i
		}
	}
	return ans
}

func main() {
	nums := []int{0, 1}
	fmt.Println(findMaxLength(nums))
}
