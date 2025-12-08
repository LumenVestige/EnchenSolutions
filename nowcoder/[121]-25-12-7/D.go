package main

import (
	"bufio"
	"fmt"
	"os"
	"runtime/debug"
)

func main() {
	_in, _out := os.Stdin, os.Stdout
	in, out := bufio.NewReader(_in), bufio.NewWriter(_out)
	defer out.Flush()
	debug.SetGCPercent(-1)
	var n, k int
	var str string
	fmt.Fscan(in, &n, &k, &str)
	cnt := make([]int, n+1)
	c, p := 0, 0
	for i := 0; i < n; i++ {
		if str[i] == '1' {
			c = 0
		} else {
			c++
		}
		if c == k {
			c = 0
			p++
		}
		cnt[i+1] = p
	}
	p = 0
	ans := make([]int, n+1)
	for i := 0; i <= n; i++ {
		for p < n && cnt[p+1] <= i {
			p++
		}
		ans[i] = p
	}
	for _, v := range ans {
		fmt.Fprint(out, v, " ")
	}
}
