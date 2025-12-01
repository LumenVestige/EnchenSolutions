package main

import (
	"fmt"
	"strconv"
)

func myAtoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}
func main() {
	fmt.Println(myAtoi("1234"))
}
