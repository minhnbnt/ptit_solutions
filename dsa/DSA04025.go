package main

import "fmt"

type Matrix [2][2]uint64

const MOD = uint64(1e9 + 7)

func (self Matrix) Multiple(other *Matrix) Matrix {

	result := Matrix{}

	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {

			for k := 0; k < 2; k++ {
				result[i][j] += (self[i][k] * other[k][j]) % MOD
				result[i][j] %= MOD
			}
		}
	}

	return result
}

func (self Matrix) Pow(n uint) Matrix {

	if n == 0 {
		return Matrix{
			{1, 0},
			{0, 1},
		}
	}

	if n%2 == 0 {
		squareRooted := self.Pow(n / 2)
		return squareRooted.Multiple(&squareRooted)
	}

	return self.Pow(n - 1).Multiple(&self)
}

func Fibonacci(n uint) uint64 {

	matrix := Matrix{
		{1, 1},
		{1, 0},
	}

	powered := matrix.Pow(n - 1)

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
