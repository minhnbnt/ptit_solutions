package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n, k int
		fmt.Scan(&n, &k)

		set := map[int]bool{}
		array := make([]int, k+1)

		for i := 1; i <= k; i++ {
			fmt.Scan(&array[i])
			set[array[i]] = true
		}

		i := k
		for i > 0 && array[i] == n-k+i {
			i--
		}

		if i == 0 {
			fmt.Println(k)
			continue
		}

		array[i] += 1
		for ; i < k; i++ {
			array[i+1] = array[i] + 1
		}

		newElement := 0
		for i := 1; i <= k; i++ {
			if _, has := set[array[i]]; !has {
				newElement += 1
			}
		}

		fmt.Println(newElement)
	}
}
