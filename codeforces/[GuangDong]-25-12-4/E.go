package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"runtime/debug"
)

func CF106210E(_in io.Reader, _w io.Writer) {
	in := bufio.NewReader(_in)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, t int
	Fscan(in, &n, &t)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		Fscan(in, &nums[i])
	}
	// 预处理一下，构建prefix前缀和
	prefix := make([]int, n+1)
	for i := 1; i <= n; i++ {
		prefix[i] = prefix[i-1] + nums[i-1]
	}
	solve := func() {
		var L, R int
		Fscan(in, &L, &R)
		for i := L; i <= R; i++ {
			for j := i; j <= R; j++ {
				if (prefix[j]-prefix[i-1])%3 == 0 {
					Fprintln(out, "Yes")
					return
				}
			}
		}
		Fprintln(out, "No")
	}
	for ; t > 0; t-- {
		solve()
	}
}

func main() {
	debug.SetGCPercent(-1)
	CF106210E(os.Stdin, os.Stdout)
}
