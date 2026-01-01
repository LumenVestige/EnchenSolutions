package main

import "fmt"

func dietPlanPerformance(calories []int, k int, lower int, upper int) int {
	n := len(calories)
	left, right, tmp, ans := 0, 0, 0, 0
	for right < n {
		// 入
		tmp += calories[right]
		// 判断是否出去了
		if right-left+1 == k {
			if tmp > upper {
				ans++
			}
			if tmp < lower {
				ans--
			}
			tmp -= calories[left]
			left++
		}
		right++
	}
	return ans
}
func main() {
	calories := []int{1, 2, 3, 4, 5}
	fmt.Println(dietPlanPerformance(calories, 1, 3, 3))
}
