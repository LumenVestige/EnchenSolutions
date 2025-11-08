package main

import "fmt"

func numIdenticalPairs(nums []int) int {
	ans := 0
	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			if nums[i] == nums[j] && i < j {
				ans++
			}
		}
	}
	return ans
}
func main() {
	fmt.Println(numIdenticalPairs([]int{1, 2, 3, 1, 1, 3}))
}
