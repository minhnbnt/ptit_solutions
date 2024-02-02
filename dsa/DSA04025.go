package main

import "fmt"

const MOD = uint64(1e9 + 7)

func MultipleMatrix(mx1 [2][2]uint64, mx2 [2][2]uint64) [2][2]uint64 {

	result := [2][2]uint64{}

	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {

			for k := 0; k < 2; k++ {
				result[i][j] += (mx1[i][k] * mx2[k][j]) % MOD
				result[i][j] %= MOD
			}
		}
	}

	return result
}

func PowerMatrix(matrix [2][2]uint64, n uint) [2][2]uint64 {

	if n == 0 {
		return [2][2]uint64{{1, 0}, {0, 1}}
	}

	if n%2 == 0 {
		squareRooted := PowerMatrix(matrix, n/2)
		return MultipleMatrix(squareRooted, squareRooted)
	}

	return MultipleMatrix(PowerMatrix(matrix, n-1), matrix)
}

func Fibonacci(n uint) uint64 {

	matrix := [2][2]uint64{{1, 1}, {1, 0}}
	powered := PowerMatrix(matrix, n-1)

	return powered[0][0]
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n uint
		fmt.Scan(&n)

		fmt.Println(Fibonacci(n))
	}
}
