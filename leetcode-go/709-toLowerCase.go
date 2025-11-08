package main

import "fmt"

func toLowerCase(s string) string {
	result := []byte(s)
	for i, v := range result {
		if v >= 'A' && v <= 'Z' {
			result[i] = v + 32
		}
	}
	return string(result)
}
func main() {
	fmt.Println(toLowerCase("Hello"))
}
