package main

import "fmt"

func countPartitions(nums []int) int {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum&1 == 1 {
		return 0
	}
	return len(nums) - 1
}

func main() {
	nums := []int{1, 2, 3}
	fmt.Println(countPartitions(nums))
}
