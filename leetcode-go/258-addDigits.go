package main

import "fmt"

func addDigits(num int) int {
	if num < 10 {
		return num
	}
	ans := 0
	for num != 0 {
		ans += num % 10
		num /= 10
	}
	return addDigits(ans)
}

func main() {
	fmt.Println(addDigits(38))
}
