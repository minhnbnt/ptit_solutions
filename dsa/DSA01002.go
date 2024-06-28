/*
Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N.

Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử tiếp theo của X[].
Ví dụ N=5, K=3, X[] ={2, 3, 4} thì tập con tiếp theo của X[] là {2, 3, 5}.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test.

Mỗi bộ test gồm hai dòng:

Dòng thứ nhất là hai số N và K;
Dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, ..,
N.

T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input
2
5 3
1 4 5
5 3
3 4 5

Output
2 3 4
1 2 3
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n, k int
		fmt.Scan(&n, &k)

		array := make([]int, k)
		for i := 0; i < k; i++ {
			fmt.Scan(&array[i])
		}

		i := k
		for i > 0 && array[i-1] == n-k+i {
			i--
		}

		if i == 0 {

			for i := 0; i < k; i++ {
				fmt.Printf("%v ", i+1)
			}

			fmt.Println()
			continue
		}

		i -= 1
		array[i]++
		for ; i < k-1; i++ {
			array[i+1] = array[i] + 1
		}

		for i := 0; i < k; i++ {
			fmt.Printf("%v ", array[i])
		}

		fmt.Println()
	}
}
