package main

import "fmt"

func maxBalancedSubarray(nums []int) int {
	pos := map[int64]int{0: -1}
	var xorv, diff int
	ans := 0
	for i, x := range nums {
		xorv ^= x
		diff += x%2*2 - 1
		key := int64(uint64(uint32(xorv))<<32 | uint64(uint32(diff)))
		if j, ok := pos[key]; ok {
			ans = max(ans, i-j)
		} else {
			pos[key] = i
		}
	}
	return ans
}
func main() {
	nums := []int{3, 1, 3, 2, 0}
	fmt.Println(maxBalancedSubarray(nums))
}
