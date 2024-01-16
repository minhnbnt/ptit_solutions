package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		slice := make([]int, size)
		for i := 0; i < size; i++ {
			fmt.Scan(&slice[i])
		}

		currentSum, result := 0, 0
		for _, x := range slice {

			currentSum += x

			if currentSum < 0 {
				currentSum = 0
			}

			if currentSum > result {
				result = currentSum
			}
		}

		fmt.Println(result)
	}
}
