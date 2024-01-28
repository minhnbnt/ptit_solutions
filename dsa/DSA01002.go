package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n, k int
		fmt.Scan(&n, &k)

		array := make([]int, k)
		for i := 0; i < k; i++ {
			fmt.Scan(&array[i])
		}

		i := k
		for i > 0 && array[i-1] == n-k+i {
			i--
		}

		if i == 0 {

			for i := 0; i < k; i++ {
				fmt.Printf("%v ", i+1)
			}

			fmt.Println()
			continue
		}

		i -= 1
		array[i]++
		for ; i < k-1; i++ {
			array[i+1] = array[i] + 1
		}

		for i := 0; i < k; i++ {
			fmt.Printf("%v ", array[i])
		}

		fmt.Println()
	}
}
