/*
Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.
Hãy tìm xâu con đối xứng dài nhất của S.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.

Output:
Với mỗi test, in ra đáp án tìm được.

Ví dụ:

Input:
2
abcbadd
aaaaa

Output:
5
5
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var s string
		fmt.Scanln(&s)

		length := len(s)

		dp := make([][]bool, length)
		for i := range dp {
			dp[i] = make([]bool, length)
		}

		result := 0

		for i := range s {

			for j := 0; j < length-i; j++ {

				k := i + j

				if s[j] != s[k] {
					continue
				}

				if !(j+1 > k-1 || dp[j+1][k-1]) {
					continue
				}

				dp[j][k] = true

				if result <= i {
					result = i + 1
				}
			}
		}

		fmt.Println(result)
	}
}
