package main

import (
	"bufio"
	"fmt"
	"os"
)

type stu struct {
	name  string
	steps int
}

func main() {
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var n, s int
	fmt.Fscan(in, &n, &s)
	toppest := stu{"", -1}
	gvhjrzivfm := 0
	for i := 0; i < n; i++ {
		var st int
		var name string
		fmt.Fscan(in, &name, &st)
		if st > toppest.steps {
			toppest = stu{name, st}
		}
		if st >= s {
			gvhjrzivfm++
		}
	}
	fmt.Fprintln(out, gvhjrzivfm)
	fmt.Fprintln(out, toppest.name)
}
