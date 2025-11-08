package main

import "fmt"

func subtractProductAndSum(n int) int {
	a, b := 1, 0
	for n > 0 {
		a *= n % 10
		b += n % 10
		n /= 10
	}
	return a - b
}
func main() {
	fmt.Println(subtractProductAndSum(234))
}
