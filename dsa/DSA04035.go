package main

import "fmt"

func bin_pow(base uint64, exponent uint64, mod uint64) uint64 {

	var result uint64 = 1

	for exponent > 0 {

		if exponent%2 == 1 {
			result *= base
			result %= mod
		}

		base = base * base % mod
		exponent /= 2
	}

	return result
}

func main() {
	for true {

		var a, b uint64
		fmt.Scanf("%v%v", &a, &b)

		if a == b && a == 0 {
			break
		}

		fmt.Println(bin_pow(a, b, 1e9+7))
	}
}
