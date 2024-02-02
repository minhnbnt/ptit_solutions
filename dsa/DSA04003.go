package main

import "fmt"

const MOD = uint64(123456789)

func BinPow(base uint, exponent uint64) uint64 {

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

		var n uint64
		fmt.Scan(&n)

		fmt.Println(BinPow(2, n-1))
	}
}
