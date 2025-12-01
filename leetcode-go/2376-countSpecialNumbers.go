package main

import (
	"fmt"
	"strconv"
)

func countSpecialNumbers(n int) int {
	strNum := strconv.Itoa(n)
	// 互不相同，则不能有相同的数字
	var dfs func(int, bool, int) int
	memo := make([][2][1 << 10]int, 20)
	for i := range memo {
		for j := range memo[i] {
			for l := range memo[i][j] {
				memo[i][j][l] = -1
			}
		}
	}
	dfs = func(pos int, isLimit bool, mask int) (res int) {
		if pos == len(strNum) {
			if mask == 0 {
				return 0
			}
			return 1
		}
		var index int
		if isLimit {
			index = 1
		} else {
			index = 0
		}
		p := &memo[pos][index][mask]
		if *p != -1 {
			return *p
		}
		defer func() { *p = res }()
		var up int
		if isLimit {
			up = int(strNum[pos] - '0')
		} else {
			up = 9
		}
		res, down := 0, 0
		if mask == 0 {
			res += dfs(pos+1, false, mask)
			down = 1
		}
		for i := down; i <= up; i++ {
			if (mask >> i & 1) == 0 { // 只有当没有出现过时候才能进入
				res += dfs(pos+1, isLimit && up == i, mask|(1<<i))
			}
		}
		return
	}
	return dfs(0, true, 0)
}

func main() {
	fmt.Println(countSpecialNumbers(135))
}
