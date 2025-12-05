package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func CF2171C(_in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	in := bufio.NewReader(_in)
	defer out.Flush()
	var t int
	Fscan(in, &t)
	solve := func() {
		var n int
		nA, nB := 0, 0
		Fscan(in, &n)
		numsA := make([]int, n)
		numsB := make([]int, n)
		xor := 0
		for i := 0; i < n; i++ {
			Fscan(in, &numsA[i])
			xor ^= numsA[i]
		}
		for i := 0; i < n; i++ {
			Fscan(in, &numsB[i])
			xor ^= numsB[i]
		}
		if xor == 0 {
			Fprintln(out, "Tie")
			return
		}
		for i := 0; i < n; i++ {
			if numsA[i] != numsB[i] {
				if ((i + 1) & 1) == 1 {
					nA = 1
					nB = 0
				} else {
					nA = 0
					nB = 1
				}
			}
		}
		if nA > nB {
			Fprintln(out, "Ajisai")
		} else {
			Fprintln(out, "Mai")
		}
	}
	for ; t > 0; t-- {
		solve()
	}
}

func main() {
	CF2171C(os.Stdin, os.Stdout)
}
