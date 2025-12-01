package main

import (
	"fmt"
	"strconv"
)

func sumAndMultiply(n int) int64 {
	sum, str := 0, ""
	for n != 0 {
		if n%10 != 0 {
			str += strconv.Itoa(n % 10)
		}
		sum += n % 10
		n /= 10
	}
	b := []byte(str)
	for i := 0; i < len(str)/2; i++ {
		b[i], b[len(b)-i-1] = b[len(b)-i-1], b[i]
	}
	str = string(b)
	i64, _ := strconv.ParseInt(str, 10, 64)
	return i64 * int64(sum)
}

func main() {
	fmt.Println(sumAndMultiply(21))
}
