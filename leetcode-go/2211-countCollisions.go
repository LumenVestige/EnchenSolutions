package main

import (
	"container/list"
	"fmt"
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
	totalRun, L, R := 0, 0, 0
	flag := true
	for _, v := range directions {
		if v != 'S' {
			totalRun++
		}
		if flag && v == 'L' {
			L++
		} else {
			flag = false
		}
	}
	flag = true
	for i := len(directions) - 1; i >= 0; i-- {
		v := directions[i]
		if flag && v == 'R' {
			L++
		} else {
			flag = false
		}
	}
	return totalRun - L - R
}
func main() {
	fmt.Println(countCollisions2("RSL"))
}
