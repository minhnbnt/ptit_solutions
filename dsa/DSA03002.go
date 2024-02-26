package main

import "fmt"

func GetDiff(number int) (int, int) {

	currentDiff := 1
	largerDiff, smallerDiff := 0, 0

	for ; number > 0; number /= 10 {

		switch number % 10 {
		case 5:
			largerDiff += currentDiff
		case 6:
			smallerDiff -= currentDiff
		}

		currentDiff *= 10
	}

	return largerDiff, smallerDiff
}

func main() {

	var a, b int
	fmt.Scan(&a, &b)

	largerSum, smallerSum := a+b, a+b

	largerDiff, smallerDiff := GetDiff(a)

	largerSum += largerDiff
	smallerSum -= smallerDiff

	largerDiff, smallerDiff = GetDiff(b)

	largerSum += largerDiff
	smallerSum -= smallerDiff

	fmt.Println(smallerSum, largerSum)
}
