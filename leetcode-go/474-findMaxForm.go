package main

import "fmt"

func count(str string) (int, int) {
	zero, one := 0, 0
	for _, v := range str {
		if v == '0' {
			zero++
		} else {
			one++
		}
	}
	return zero, one
}

func findMaxForm(str []string, m int, n int) int {
	dp := make([][][]int, len(str)+1)
	for i := 0; i <= len(str); i++ {
		dp[i] = make([][]int, m+1)
		for j := 0; j <= m; j++ {
			dp[i][j] = make([]int, n+1)
		}
	}
	for i := 0; i < len(str); i++ {
		cnt0, cnt1 := count(str[i])
		for j := 0; j <= m; j++ {
			for k := 0; k <= n; k++ {
				if cnt0 <= j && cnt1 <= k {
					dp[i+1][j][k] = max(dp[i][j][k], dp[i][j-cnt0][k-cnt1]+1)
				} else {
					dp[i+1][j][k] = dp[i][j][k]
				}
			}
		}
	}
	return dp[len(str)][m][n]
}

func main() {
	str := []string{"10", "0001", "111001", "1", "0"}
	fmt.Println(findMaxForm(str, 5, 3))
}
