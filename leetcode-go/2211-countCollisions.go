package main

import (
	"container/list"
	"fmt"
	"strings"
)

// 用栈做模拟
func countCollisions(directions string) int {
	st := list.New()
	ans := 0
	var inCheck func(rune)
	inCheck = func(c rune) {
		if st.Len() == 0 || c == 'R' {
			st.PushBack(c)
			return
		}
		b := st.Back().Value
		if (c == 'L' && b == 'R') || (c == 'L' && b == 'S') || (c == 'S' && b == 'R') {
			// crash
			st.Remove(st.Back())
			if c == 'S' || b == 'S' {
				ans += 1
			} else {
				ans += 2
			}
			inCheck('S')
		} else {
			st.PushBack(c)
		}
	}
	for _, v := range directions {
		inCheck(v)
	}
	return ans
}

// 脑筋急转弯。。。
func countCollisions2(directions string) int {
	directions = strings.TrimRight(directions, "R")
	directions = strings.TrimLeft(directions, "L")
	//ans := 0
	//for _, v := range directions {
	//	if v != 'S' {
	//		ans++
	//	}
	//}
	return len(directions) - strings.Count(directions, "S")
}
func main() {
	fmt.Println(countCollisions2("RSL"))
}
