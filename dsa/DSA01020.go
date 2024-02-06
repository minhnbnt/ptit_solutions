package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var bitStr string
		fmt.Scan(&bitStr)

		length := len(bitStr)
		bits := []rune(bitStr)
		for i := length - 1; i >= 0; i-- {

			if bits[i] == '1' {
				bits[i] = '0'
				break
			}

			bits[i] = '1'
		}

		fmt.Println(string(bits))
	}
}
