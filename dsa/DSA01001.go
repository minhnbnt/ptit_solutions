package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var bitStr string
		fmt.Scanln(&bitStr)
		bitsArray := []rune(bitStr)

		i := len(bitsArray) - 1
		for ; i >= 0 && bitsArray[i] == '1'; i-- {
			bitsArray[i] = '0'
		}

		if i >= 0 {
			bitsArray[i] = '1'
		}

		fmt.Println(string(bitsArray))
	}
}
