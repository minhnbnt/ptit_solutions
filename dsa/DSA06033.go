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

		longestDistance := -1
		for i, leftEle := range slice {
			for j := size - 1; j > i; j-- {

				if slice[j] <= leftEle {
					continue
				}

				distance := j - i
				if longestDistance < distance {
					longestDistance = distance
				}

				break
			}
		}

		fmt.Println(longestDistance)
	}
}
