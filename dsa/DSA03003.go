/*
Cho mảng A[] gồm N phần tử.Nhiệm vụ của bạn là tìm giá trị lớn nhất của biểu
thức \sum_{i=0}^{n-1} i * A_{i} bằng cách sắp đặt lại các phần tử trong mảng.

Chú ý, kết quả của bài toán có thể rất lớn vì vậy bạn hãy đưa ra kết quả lấy
modulo với 10^9+7.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng:
dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i]
tương ứng với các phần tử của mảng A[];

các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N, A[i] ≤10^7.

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input:
2
5
5 3 2 4 1
3
1 2 3

Output:
40
8
*/

package main

import (
	"fmt"
	"sort"
)

const MOD = int64(1e9 + 7)

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

		sort.Ints(slice)

		var result int64 = 0
		for i, element := range slice {
			result += int64(element) * int64(i)
			result %= MOD
		}

		fmt.Println(result)
	}
}
