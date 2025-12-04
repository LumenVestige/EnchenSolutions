package main

import (
	"fmt"
	"sort"
)

type UnionFind interface {
	Merge(x int, y int)
	Same(x int, y int) bool
	Find(x int) int
}

type unionFind struct {
	parent []int
}

func (u unionFind) Merge(x int, y int) {
	rootX, rootY := u.Find(x), u.Find(y)
	u.parent[rootX] = rootY
}

func (u unionFind) Same(x int, y int) bool {
	return u.Find(x) == u.Find(y)
}

func (u unionFind) Find(x int) int {
	for x != u.parent[x] {
		u.parent[x] = u.parent[u.parent[x]]
		x = u.parent[x]
	}
	return x
}

func NewUnionFind(x int) UnionFind {
	uf := unionFind{parent: make([]int, x)}
	for i := 0; i < x; i++ {
		uf.parent[i] = i
	}
	return uf
}

func accountsMerge(accounts [][]string) [][]string {
	m := len(accounts)
	uf := NewUnionFind(m)
	um := map[string]int{}
	for i := 0; i < m; i++ {
		for j := 1; j < len(accounts[i]); j++ {
			if v, ok := um[accounts[i][j]]; ok {
				uf.Merge(i, v)
			} else {
				um[accounts[i][j]] = i
			}
		}
	}
	cnt := map[int][]string{}
	for k, v := range um {
		cnt[uf.Find(v)] = append(cnt[uf.Find(v)], k)
	}
	ans := make([][]string, 0)
	for k, v := range cnt {
		tmp := []string{accounts[k][0]}
		sort.Strings(v)
		tmp = append(tmp, v...)
		ans = append(ans, tmp)
	}
	return ans
}
func main() {
	accounts := [][]string{{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}}
	for _, item := range accountsMerge(accounts) {
		for _, i := range item {
			fmt.Print(i, " ")
		}
		fmt.Println()
	}
}
