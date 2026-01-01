package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var s, n int
	fmt.Fscan(in, &s, &n)
	fmt.Fprintln(out, s)
	for i := 0; i < n; i++ {
		var tmp int
		fmt.Fscan(in, &tmp)
		s += tmp
	}
	fmt.Fprintln(out, s)
}
