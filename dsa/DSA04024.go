package main

import "fmt"

const MOD = int64(1e9 + 7)

func MultipleMatrix(mx1 [][]int64, mx2 [][]int64) [][]int64 {

	rank := len(mx1)

	result := make([][]int64, rank)

	for i := 0; i < rank; i++ {

		result[i] = make([]int64, rank)

		for j := 0; j < rank; j++ {

			for k := 0; k < rank; k++ {
				result[i][j] += (mx1[i][k] * mx2[k][j]) % MOD
				result[i][j] %= MOD
			}
		}
	}

	return result
}

func PowerMatrix(matrix [][]int64, exponent uint) [][]int64 {

	rank := len(matrix)

	if exponent == 0 {

		result := make([][]int64, rank)

		for i := 0; i < rank; i++ {
			result[i] = make([]int64, rank)
			result[i][i] = 1
		}

		return result
	}

	if exponent%2 == 0 {
		squareRooted := PowerMatrix(matrix, exponent/2)
		return MultipleMatrix(squareRooted, squareRooted)
	}

	divided := PowerMatrix(matrix, exponent-1)
	return MultipleMatrix(divided, matrix)
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var rank int
		var exp uint
		fmt.Scan(&rank, &exp)

		matrix := make([][]int64, rank)
		for i := 0; i < rank; i++ {
			matrix[i] = make([]int64, rank)
			for j := 0; j < rank; j++ {
				fmt.Scan(&matrix[i][j])
			}
		}

		result := PowerMatrix(matrix, exp)

		var sum int64 = 0
		for i := 0; i < rank; i++ {
			sum += result[i][rank-1]
			sum %= MOD
		}

		fmt.Println(sum)
	}
}
