package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array := []string{"6", "8"}
		for i := 0; len(array[i]) < size; i++ {
			array = append(array, array[i]+"6", array[i]+"8")
		}

		fmt.Println(len(array))

		for _, num := range array {
			fmt.Printf("%v ", num)
		}

		fmt.Println()
	}
}
