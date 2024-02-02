package main

import "fmt"

func main() {

	var a, b int
	fmt.Scan(&a, &b)

	largerSum, smallerSum := a+b, a+b

	currentDiff := 1
	for ; a > 0; a /= 10 {

		if a%10 == 5 {
			largerSum += currentDiff
		} else if a%10 == 6 {
			smallerSum -= currentDiff
		}

		currentDiff *= 10
	}

	currentDiff = 1
	for ; b > 0; b /= 10 {

		if b%10 == 5 {
			largerSum += currentDiff
		} else if b%10 == 6 {
			smallerSum -= currentDiff
		}

		currentDiff *= 10
	}

	fmt.Println(smallerSum, largerSum)
}
