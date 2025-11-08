package main

import "fmt"

func peakIndexInMountainArray(arr []int) int {
	check := func(i int) int {
		if arr[i-1] < arr[i] && arr[i] > arr[i+1] {
			return 0
		}
		if arr[i-1] > arr[i] {
			return 1
		}
		return 2
	}
	left, right := 1, len(arr)-1
	for left+1 != right {
		mid := (left + right) / 2
		if check(mid) == 1 {
			right = mid
		} else if check(mid) == 2 {
			left = mid
		} else {
			return mid
		}
	}
	return right - 1
}
func main() {
	arr := []int{0, 10, 5, 2}
	fmt.Println(peakIndexInMountainArray(arr))
}
