package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var num, deno int
		fmt.Scan(&num, &deno)

		for deno%num > 0 {

			currentDeno := (deno / num) + 1
			fmt.Printf("1/%d + ", currentDeno)

			num = (num * currentDeno) - deno
			deno *= currentDeno
		}

		fmt.Printf("1/%d\n", deno/num)
	}
}
