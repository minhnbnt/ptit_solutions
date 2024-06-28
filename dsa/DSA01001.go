/*
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân tiếp theo của X[].

Ví dụ X[] ="010101" thì xâu nhị phân tiếp theo của X[] là "010110".

Input:
Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.

T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
010101
111111

Output
010110
0000
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var bitStr string
		fmt.Scanln(&bitStr)
		bitsArray := []rune(bitStr)

		i := len(bitsArray) - 1
		for ; i >= 0 && bitsArray[i] == '1'; i-- {
			bitsArray[i] = '0'
		}

		if i >= 0 {
			bitsArray[i] = '1'
		}

		fmt.Println(string(bitsArray))
	}
}
