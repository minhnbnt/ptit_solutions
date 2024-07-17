/*
Cho số nguyên dương N được biểu diễn như một xâu ký tự số.
Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi các xâu con của N.
Ví dụ N=”1234” ta có kết quả là:
1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.

T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤10^12.

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input
2
1234
421

Output
1670
491
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n uint64
		fmt.Scan(&n)

		result := uint64(0)
		for ; n > 0; n /= 10 {

			mod := uint64(10)

			for {

				add := n % mod
				result += add

				mod *= 10

				if add == n {
					break
				}
			}
		}

		fmt.Println(result)
	}
}
