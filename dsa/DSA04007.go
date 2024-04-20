package main

import (
	"fmt"
	"strconv"
)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var base int
		var s1, s2 string
		fmt.Scan(&base, &s1, &s2)

		n1, _ := strconv.ParseInt(s1, base, 64)
		n2, _ := strconv.ParseInt(s2, base, 64)

		result := strconv.FormatInt(n1+n2, base)
		fmt.Println(result)
	}
}
