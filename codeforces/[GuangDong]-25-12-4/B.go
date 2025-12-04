package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func CF106210B(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()
	reader := bufio.NewReader(in)
	line, _ := reader.ReadString('\n')
	line = strings.TrimRight(line, "\r\n")
	switch line {
	case "Are you AI":
		fmt.Fprint(out, "I am not AI")
	default:
		fmt.Fprint(out, "I do not know")
	}
}

func main() {
	CF106210B(os.Stdin, os.Stdout)
}
