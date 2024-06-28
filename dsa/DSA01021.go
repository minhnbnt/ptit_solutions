/*
Cho số nguyên dương (1<N<40) và số nguyên dương K<N.
Với 1 tổ hợp chập K phần tử của N, hãy cho biết tổ hợp tiếp theo sẽ có bao nhiêu
phần tử mới.

Nếu tổ hợp đã cho là cuối cùng thì kết quả là K.

Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai
dòng

Dòng 1: hai số nguyên dương N và K (K<N)
Dòng 2: ghi K số của tổ hợp ban đầu.
Theo đúng thứ tự tăng dần, không có số nào trùng nhau.

Kết quả: Với mỗi bộ dữ liệu in ra số lượng phần tử mới.

Ví dụ:

INPUT:
3
5 3
1 3 5
5 3
1 4 5
6 4
3 4 5 6

OUTPUT:
1
2
4
*/

package main

import "fmt"

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n, k int
		fmt.Scan(&n, &k)

		set := map[int]bool{}
		array := make([]int, k+1)

		for i := 1; i <= k; i++ {
			fmt.Scan(&array[i])
			set[array[i]] = true
		}

		i := k
		for i > 0 && array[i] == n-k+i {
			i--
		}

		if i == 0 {
			fmt.Println(k)
			continue
		}

		array[i] += 1
		for ; i < k; i++ {
			array[i+1] = array[i] + 1
		}

		newElement := 0
		for i := 1; i <= k; i++ {
			if _, has := set[array[i]]; !has {
				newElement += 1
			}
		}

		fmt.Println(newElement)
	}
}
