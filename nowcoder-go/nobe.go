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
	var str []byte
	fmt.Fscan(r, &str)
	for i := 0; i < len(str)/2; i++ {
		str[i], str[len(str)-i-1] = str[len(str)-i-1], str[i]
	}
	fmt.Println(string(str))
}
