package main

import "fmt"

func checkSubarraySum(nums []int, k int) bool {
	pos := map[int]int{0: -1}
	key, tmp := 0, 0
	for i, v := range nums {
		tmp += v
		key = tmp % k
		if j, ok := pos[key]; ok {
			if i-j >= 2 {
				return true
			}
		} else {
			pos[key] = i
		}
	}
	return false
}
func main() {
	nums := []int{0}
	fmt.Println(checkSubarraySum(nums, 1))
}
