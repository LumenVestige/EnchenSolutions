package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"runtime/debug"
)

func lowerBound(nums *[]int, target int) int {
	left, right := -1, len(*nums)
	for left+1 != right {
		mid := (left + right) / 2
		if (*nums)[mid] >= target {
			right = mid
		} else {
			left = mid
		}
	}
	return right
}

func CF106210I(_in io.Reader, w io.Writer) {
	in := bufio.NewReader(_in)
	var n int
	Fscan(in, &n)
	nums := make([]int, n)
	pos := map[int][]int{}
	for i := 0; i < n; i++ {
		Fscan(in, &nums[i])
		pos[nums[i]] = append(pos[nums[i]], i)
	}
	ans := 0
	for i := 0; i < n; i++ {
		// 当前数字所有位置数组
		curPos := pos[nums[i]]
		posNum := lowerBound(&curPos, i)
		ans += n - (i + 1) - (len(curPos) - (posNum + 1))
	}
	Fprintln(w, ans)
}

func main() {
	debug.SetGCPercent(-1)
	CF106210I(os.Stdin, os.Stdout)
}
