/*
Cho dãy số A[] gồm n số nguyên dương.
Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng,
trong đó hàng thứ n là dãy số A[],
hàng i là tổng hai phần tử liên tiếp của hàng i+1 (1≤i≤n-1).

Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:
[48]
[20, 28]
[8, 12, 16]
[3, 5, 7, 9]
[1, 2, 3, 4, 5]

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng tiếp theo đưa vào các bộ test.
Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N là số lượng phần tử của dãy số A[];
dòng tiếp theo đưa vào N số của mảng A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10;

Output:
Đưa ra kết quả mỗi test theo từng dòng. Mỗi dòng của tam giác tổng được bao bởi ký tự [, ].

Input
1
5
1 2 3 4 5

Output
[48] [20 28] [8 12 16] [3 5 7 9 ] [1 2 3 4 5 ]
*/

package main

import (
	"fmt"
	"reflect"
)

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array := make([]int, size)
		for i := range array {
			fmt.Scan(&array[i])
		}

		results := [][]int{}

		for {

			arrayLength := len(array)
			results = append(results, array)

			if arrayLength == 1 {
				break
			}

			newArray := make([]int, arrayLength-1)
			for i := range newArray {
				newArray[i] = array[i] + array[i+1]
			}

			array = newArray
		}

		for _, result := range Reverse(results) {
			fmt.Printf("%v ", result)
		}

		fmt.Println()
	}
}

func Reverse[T any](array []T) []T {

	swapFunc := reflect.Swapper(array)

	left, right := 0, len(array)-1

	for left < right {
		swapFunc(left, right)
		left, right = left+1, right-1
	}

	return array
}
