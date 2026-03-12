package main

import (
	"fmt"
	"os"
	"sort"
)

func main() {
	in := os.Stdin
	var n, m int
	fmt.Fscan(in, &n, &m)
	vec := make([][]int, n)
	ma := map[int]int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			var tmp int
			fmt.Fscan(in, &tmp)
			if _, ok := ma[tmp]; !ok {
				vec[i] = append(vec[i], tmp)
				ma[tmp]++
			}
		}
		sort.Ints(vec[i])
	}
	for i := 0; i < n; i++ {
		for j := 0; j < len(vec[i]); j++ {
			fmt.Print(vec[i][j], " ")
		}
		fmt.Println()
	}
}
