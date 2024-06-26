/*
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân trước của X[].

Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”.
Với xâu X[] =“000001” thì xâu nhị trước của X[] là “000000”.

Chú ý: nếu xâu dữ liệu trong input là xâu đầu tiên thì trước nó sẽ là xâu cuối
cùng.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤10^3.

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:
Input:
2
010101
111111

Output:
010100
111110
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var bitStr string
		fmt.Scan(&bitStr)

		length := len(bitStr)
		bits := []rune(bitStr)
		for i := length - 1; i >= 0; i-- {

			if bits[i] == '1' {
				bits[i] = '0'
				break
			}

			bits[i] = '1'
		}

		fmt.Println(string(bits))
	}
}
