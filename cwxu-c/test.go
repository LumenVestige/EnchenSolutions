package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/user", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintln(w, "Hello from user-service")
	})
	fmt.Println("user-service running on :9000")
	http.ListenAndServe(":9000", nil)
}
