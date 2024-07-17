/*
Giả sử bạn cần viết N ký tự giống nhau lên màn hình. Bạn chỉ được phép thực hiện
ba thao tác dưới đây với chi phí thời gian khác nhau:

Thao tác insert: chèn một ký tự với thời gian là X.
Thao tác delete: loại bỏ ký tự cuối cùng với thời gian là Y.
Thao tác copying: copy và paste tất cả các ký tự đã viết để số ký tự được nhân
đôi với thời gian là Z.

Hãy tìm thời gian ít nhất để có thể đưa ra màn hình N ký tự giống nhau.

Ví dụ với N = 9, X =1, Y = 2, Z =1
ta có kết quả là 5 bằng cách thực hiện: insert, insert, copying, copying,
insert.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test.
Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số các ký tự giống nhau cần
viết lên màn hình;
dòng tiếp theo đưa vào bộ ba số X, Y, Z tương ứng với thời gian thực hiện ba
thao tác;

các số được viết cách nhau một vài khoảng trống.
T, N, X, Y, Z thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100; 1≤X, Y, Z ≤100.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input
2
9
1 2 1
10
2 5 4

Output:
5
14
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var length int
		fmt.Scan(&length)

		var insertCost, deleteCost, copyCost int
		fmt.Scan(&insertCost, &deleteCost, &copyCost)

		dp := map[int]int{}
		dp[1] = insertCost

		for i := 2; i <= length; i++ {

			if i%2 == 0 {
				dp[i] = Min(dp[i/2]+copyCost, dp[i-1]+insertCost)
				continue
			}

			dp[i] = Min(dp[i-1]+insertCost, dp[(i+1)/2]+deleteCost+copyCost)
		}

		fmt.Println(dp[length])
	}
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
