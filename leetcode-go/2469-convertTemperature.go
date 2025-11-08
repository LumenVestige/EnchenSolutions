package main

import "fmt"

func convertTemperature(celsius float64) []float64 {
	var ans []float64
	ans = append(ans, celsius+273.15)
	ans = append(ans, celsius*1.80+32.00)
	return ans
}
func main() {
	for _, j := range convertTemperature(36.50) {
		fmt.Printf("%f ", j)
	}
}
