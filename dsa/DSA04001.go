package main

import "fmt"

const MOD = uint64(1e9 + 7)

func BinPow(base, exponent uint) uint64 {

	if exponent == 0 {
		return 1
	}

	if exponent%2 == 0 {
		squareRooted := BinPow(base, exponent/2)
		return squareRooted * squareRooted % MOD
	}

	return uint64(base) * BinPow(base, exponent-1) % MOD
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var base, exponent uint
		fmt.Scanln(&base, &exponent)

		fmt.Println(BinPow(base, exponent))
	}
}
