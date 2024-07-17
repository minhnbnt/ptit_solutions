/*
Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số
nhỏ hơn N.

Ví dụ số 100 = 102 hoặc 100 = 52 + 52 + 52 + 52.

Cho số nguyên dương N.
Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương
bằng N.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test.

Mỗi test là một số tự nhiên N được viết trên 1 dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:
Input:
3
100
6
25

Output:
1
3
1
*/

package main

import (
	"fmt"
	"math"
)

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n int
		fmt.Scan(&n)

		dp := make([]int, n+1)
		dp[1] = 1

		for i := 2; i <= n; i++ {

			result := math.MaxInt
			currentNumber := float64(i)

			for j := 1; float64(j) <= math.Sqrt(currentNumber); j++ {
				remaining := i - (j * j)
				result = Min(result, dp[remaining]+1)
			}

			dp[i] = result
		}

		fmt.Println(dp[n])
	}
}
