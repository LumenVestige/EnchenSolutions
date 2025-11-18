package main

import (
	"fmt"
	"math"
)

func maxPathScore(grid [][]int, k int) int {
	var dfs func(int, int, int) int
	memo := make([][][]int, len(grid))
	for i := 0; i < len(grid); i++ {
		memo[i] = make([][]int, len(grid[0]))
		for j := 0; j < len(grid[0]); j++ {
			memo[i][j] = make([]int, k+1)
			for c := 0; c <= k; c++ {
				memo[i][j][c] = -1
			}
		}
	}

	dfs = func(x int, y int, k int) int {
		if x < 0 || y < 0 || k < 0 {
			return math.MinInt
		}
		if x == 0 && y == 0 {
			return 0
		}
		res := &memo[x][y][k]
		if *res != -1 {
			return *res
		}
		m := grid[x][y]
		if m != 0 {
			k--
		}
		r := max(dfs(x-1, y, k), dfs(x, y-1, k)) + m
		*res = r
		return r
	}
	ans := dfs(len(grid)-1, len(grid[0])-1, k)
	if ans < 0 {
		return -1
	}
	return ans
}
func main() {
	grid := [][]int{{0, 1}, {2, 0}}
	fmt.Println(maxPathScore(grid, 1))
}
