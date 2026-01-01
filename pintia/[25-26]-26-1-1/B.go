package main

import "fmt"

func main() {
	var a, b, c int
	var t int
	fmt.Scan(&a, &b, &c, &t)
	fmt.Println(t)
	if t >= a {
		fmt.Println("yi deng jiang")
	} else if t >= b {
		fmt.Println("er deng jiang")
	} else if t >= c {
		fmt.Println("san deng jiang")
	} else {
		fmt.Println("mei jiang T_T")
	}
}
