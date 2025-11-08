package main

import "fmt"

func smallestEvenMultiple(n int) int {
	if n%2 != 0 {
		return 2 * n
	}
	return n
}
func main() {
	fmt.Println(smallestEvenMultiple(5))
}
