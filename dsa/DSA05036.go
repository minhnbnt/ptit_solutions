/*
Cho hai dãy số thực A[] và B[] đều có N phần tử, các giá trị là số thực và không
quá 100.

Hãy tính độ dài dài nhất của dãy các vị trí (không cần liên tiếp) thỏa mãn cả
hai điều kiện:
Nếu xét các vị trí đó trên dãy A[] thì dãy con thu được thỏa mãn tính chất tăng
dần (giá trị bằng nhau không được tính vào dãy tăng).
Nếu xét các vị trí đó trên dãy B[] thì dãy con thu được thỏa mãn tính chất giảm
dần (giá trị bằng nhau không được tính vào dãy giảm).

Input:
Dòng đầu ghi số bộ test (không quá 100).
Mỗi bộ test bắt đầu bởi số N (không quá 500).
Tiếp theo là N dòng, mỗi dòng ghi 2 giá trị A[i] và B[i]

Output:
Với mỗi test, ghi ra độ dài tính được trên một dòng.

Ví dụ:
Input:
3
2
1.0 1.0
1.5 0.0
3
1.0 1.0
1.0 1.0
1.0 1.0
6
1.5 9.0
2.0 2.0
2.5 6.0
3.0 5.0
4.0 2.0
10.0 5.5

Output:
2
1
4
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		array1 := make([]float64, size)
		array2 := make([]float64, size)

		for i := range array1 {
			fmt.Scan(&array1[i], &array2[i])
		}

		result := 0
		dp := make([]int, size)
		for i := range array1 {

			dp[i] = 1

			for j := 0; j < i; j++ {

				if !(array1[i] > array1[j] && array2[i] < array2[j]) {
					continue
				}

				if dp[j] >= dp[i] {
					dp[i] = dp[j] + 1
				}
			}

			if dp[i] > result {
				result = dp[i]
			}
		}

		fmt.Println(result)
	}
}
