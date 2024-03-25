package main

import "fmt"

func TowerOfHanoi(plates uint, fromRod, toRod, otherRod byte) {

	if plates == 0 {
		return
	}

	TowerOfHanoi(plates-1, fromRod, otherRod, toRod)

	fmt.Printf("%c -> %c\n", fromRod, toRod)

	TowerOfHanoi(plates-1, otherRod, toRod, fromRod)
}

func main() {

	var numberOfPlates uint
	fmt.Scan(&numberOfPlates)

	TowerOfHanoi(numberOfPlates, 'A', 'C', 'B')
}
