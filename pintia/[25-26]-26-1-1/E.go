package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	n := 0
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var a, b string
		fmt.Scan(&a, &b)

		fA, _ := strconv.ParseFloat(a, 64)
		fB, _ := strconv.ParseFloat(b, 64)
		var d string
		if fA > fB {
			d = a
		} else {
			d = b
		}
		nUpA, nUpB := math.Pow10(len(strconv.FormatFloat(fA, 'f', -1, 64))-2), math.Pow10(len(strconv.FormatFloat(fB, 'f', -1, 64))-2)
		var c string
		if nUpA*fA > nUpB*fB {
			c = a
		} else {
			c = b
		}
		fmt.Println(c, d)

	}
}
