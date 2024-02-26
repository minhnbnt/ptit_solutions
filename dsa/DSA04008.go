package main

import (
	"fmt"
	"sync"
)

const MOD = uint64(1e9 + 7)

type Matrix [2][2]uint64

func (self Matrix) Multiple(other Matrix) Matrix {

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

func (self Matrix) Pow(n int) Matrix {

	if n == 0 {
		return Matrix{
			{1, 0},
			{0, 1},
		}
	}

	if n%2 == 0 {
		squareRooted := self.Pow(n / 2)
		return squareRooted.Multiple(squareRooted)
	}

	return self.Pow(n - 1).Multiple(self)
}

func Fibonacci(n int) uint64 {

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

	lock := new(sync.Mutex)
	channels := make([]chan uint64, cases)

	defer lock.Lock()

	lock.Lock()
	go func() {

		defer lock.Unlock()

		for _, result := range channels {
			fmt.Println(<-result)
		}

	}()

	for i := range channels {

		var n int
		fmt.Scan(&n)

		channels[i] = make(chan uint64)

		go func(index, n int) {

			result := Fibonacci(n)

			channels[index] <- result
			close(channels[index])

		}(i, n)
	}
}
