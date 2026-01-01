package main

import (
	"fmt"
	"strconv"
)

func main() {
	i := 0
	s := "print()#"
	ans := 0
	for _, v := range s {
		ans ^= int(v)
	}
	fmt.Println(ans)
	for i < 20000 {
		// 求i的异或和
		tmp := 0
		str := strconv.Itoa(i)
		for _, v := range str {
			tmp ^= int(v)
		}
		fmt.Print(tmp, ans^tmp, i, "\n")
		if ans^tmp == i {
			fmt.Println(i)
			return
		}
		i++
	}
}
