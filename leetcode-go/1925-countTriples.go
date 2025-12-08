package main

import (
	"fmt"
	"math"
)

func countTriples(n int) int {
	ans := 0
	for i := 1; i <= n; i++ {
		for j := 1; i*i+j*j <= n*n; j++ {
			i2, j2 := float64(i*i), float64(j*j)
			z := int(math.Sqrt(i2 + j2))
			if float64(z*z) == i2+j2 {
				//fmt.Print(i, " ", j, " ", z, "\n")
				ans++
			}
		}
	}
	return ans
}
func main() {
	fmt.Println(countTriples(16))
}
