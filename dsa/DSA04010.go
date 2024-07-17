/*
Cho mảng A[] gồm N số có cả các số âm và số dương.

Nhiệm vụ của bạn là tìm mảng con liên tục có tổng lớn nhất của mảng.

Ví dụ với mảng A[]={-2, -5, 6, -2,-3, 1, 5, -6}
ta có kết quả là 7 tương ứng với dãy con {6, -2, -3, 1, 5}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test.

Mỗi bộ test gồm 2 dòng:

dòng thứ nhất đưa vào hai số N tương ứng với số phần tử của mảng;
dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng
trống.

T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤100; -100≤A[i] ≤100.

Output:
Đưa ra tổng con liên tục lớn nhất của mỗi test theo từng dòng.

Ví dụ:
Input:
1
8
-2 -5 6 -2 -3 1 5 -6

Output:
7
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		slice := make([]int, size)
		for i := 0; i < size; i++ {
			fmt.Scan(&slice[i])
		}

		currentSum, result := 0, 0
		for _, x := range slice {

			currentSum += x

			if currentSum < 0 {
				currentSum = 0
			}

			if currentSum > result {
				result = currentSum
			}
		}

		fmt.Println(result)
	}
}
