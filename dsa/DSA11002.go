package main

import (
	"fmt"
	"strconv"
)

func Calculate(tokens []string, index int) int {

	target := tokens[index-1]

	if value, err := strconv.Atoi(target); err == nil {
		return value
	}

	left := Calculate(tokens, index*2)
	right := Calculate(tokens, index*2+1)

	switch target {
	case "+":
		return left + right
	case "-":
		return left - right
	case "*":
		return left * right
	case "/":
		return left / right
	default:
		panic("Invalid operation: " + target)
	}
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		tokens := make([]string, size)
		for i := range tokens {
			fmt.Scan(&tokens[i])
		}

		fmt.Println(Calculate(tokens, 1))
	}
}
