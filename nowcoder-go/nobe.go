package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r, w := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	_, _ = r, w
	defer w.Flush()
	var n int
	fmt.Fscan(r, &n)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &nums[i])
	}
	for i := 0; i < n-5; i++ {
		for j := 0; j < 4; j++ {
			
		}
	}
}
