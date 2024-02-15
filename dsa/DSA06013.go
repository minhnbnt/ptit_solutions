package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size, target int
		fmt.Scan(&size, &target)

		hashMap := map[int]int{}
		for i := 0; i < size; i++ {

			var value int
			fmt.Scan(&value)

			hashMap[value]++
		}

		if counter, has := hashMap[target]; has {
			fmt.Println(counter)
		} else {
			fmt.Println(-1)
		}
	}
}
