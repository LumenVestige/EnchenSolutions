package main

import (
	"bufio"
	. "fmt"
	"io"
	"math"
	"os"
)

func CF2171B(_in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	in := bufio.NewReader(_in)
	defer out.Flush()
	var t int
	Fscan(in, &t)
	for ; t != 0; t-- {
		var n int
		Fscan(in, &n)
		// 原式子化简得到|an - a1|
		nums := make([]int, n)
		for i := 0; i < n; i++ {
			Fscan(in, &nums[i])
		}
		a1, an := &nums[0], &nums[n-1]
		if *a1 == -1 && *an != -1 {
			*a1 = *an
		} else if *a1 == -1 {
			*a1, *an = 0, 0
		} else if *an == -1 {
			*an = *a1
		}
		ans := math.Abs(float64(*an - *a1))
		Fprintln(out, ans)
		for _, v := range nums {
			if v == -1 {
				v = 0
			}
			Fprint(out, v, " ")
		}
		Fprintln(out)

	}
}

func main() {
	CF2171B(os.Stdin, os.Stdout)
}
