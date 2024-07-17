/*
Cho mảng A[] gồm n số nguyên.

Nhiệm vụ của bạn là sắp xếp mảng theo số lần xuất hiện các phần tử của mảng.

Số xuất hiện nhiều lần nhất đứng trước. Nếu hai phần tử có số lần xuất hiện như
nhau, số nhỏ hơn đứng trước.
Ví dụ A[] = {5, 5, 4, 6, 4}, ta nhận được kết quả là A[] = {4, 4, 5, 5, 6}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test.

Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, tương ứng với số phần tử của
mảng A[] và số k;

dòng tiếp theo là n số A[i];
các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^4; 1≤ k ≤10^3; 1≤ A[i] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5
*/

package main

import (
	"fmt"
	"sort"
)

type ValueCount struct {
	value   int
	counter int
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var element int
		fmt.Scan(&element)

		counterMap := make(map[int]int)
		for i := 0; i < element; i++ {

			var value int
			fmt.Scan(&value)

			counterMap[value]++
		}

		var counterSlice []ValueCount
		for key, value := range counterMap {
			element := ValueCount{value: key, counter: value}
			counterSlice = append(counterSlice, element)
		}

		sort.Slice(counterSlice, func(i, j int) bool {

			if counterSlice[i].counter != counterSlice[j].counter {
				return counterSlice[i].counter > counterSlice[j].counter
			}

			return counterSlice[i].value < counterSlice[j].value
		})

		for _, valueCounter := range counterSlice {
			for i := 0; i < valueCounter.counter; i++ {
				fmt.Printf("%v ", valueCounter.value)
			}
		}

		fmt.Println()
	}
}
