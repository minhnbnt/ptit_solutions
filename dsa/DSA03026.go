package main

import "fmt"

func GetMaxNum(digit int, sum int) string {

	if sum == 0 && digit > 1 {
		return "-1"
	}

	var result []byte

	for sum > 9 && digit > 0 {

		result = append(result, '9')

		sum -= 9
		digit--
	}

	if sum > 9 {
		return "-1"
	}

	result = append(result, byte(sum)+'0')
	digit -= 1

	for ; digit > 0; digit-- {
		result = append(result, '0')
	}

	return string(result)
}

func GetMinNum(maxNum string) string {

	if maxNum == "-1" || maxNum == "0" {
		return maxNum
	}

	var result = []byte(maxNum)
	Reverse(result)

	if result[0] == '0' {

		for i, char := range result {

			if char == '0' {
				continue
			}

			result[0] = '1'
			result[i] -= 1

			break
		}
	}

	return string(result)
}

func main() {

	var digit, sum int
	fmt.Scan(&digit, &sum)

	var maxNum = GetMaxNum(digit, sum)
	var minNum = GetMinNum(maxNum)

	fmt.Println(minNum, maxNum)
}

func Reverse[T any](array []T) {

	var left, right = 0, len(array) - 1

	for left < right {
		array[left], array[right] = array[right], array[left]
		left, right = left+1, right-1
	}
}
