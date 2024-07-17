/*
Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}.
Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong
dãy) có tổng bằng S cho trước.

Input:
Dòng đầu ghi số bộ test T (T<10).

Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤
200) và S (0 < S ≤ 40000).

Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 <
Ai ≤ 200).

Output:
Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”

Ví dụ:
Input:
2
5 6
1 2 4 3 5
10 15
2 2 2 2 2 2 2 2 2 2


Output
YES
NO
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size, targetSum int
		fmt.Scan(&size, &targetSum)

		array := make([]int, size)
		for i := range array {
			fmt.Scan(&array[i])
		}

		result := false
		dp := make([][]bool, size+1)
		dp[0] = make([]bool, targetSum+1)
		dp[0][0] = true

		for i, element := range array {

			dp[i+1] = make([]bool, targetSum+1)

			for j := 0; j <= targetSum; j++ {

				if dp[i][j] {
					dp[i+1][j] = true
					continue
				}

				sumRemaining := j - element
				if sumRemaining < 0 {
					continue
				}

				dp[i+1][j] = dp[i][sumRemaining]
			}

			if dp[i+1][targetSum] {
				result = true
				break
			}

			dp[i] = nil
		}

		if result {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
