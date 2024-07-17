/*
Cho số nguyên dương n.
Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng
n.

Dữ liệu vào: dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ liệu ghi
một số nguyên dương n duy nhất không qua 10^18.

Kết quả: Mỗi bộ dữ liệu ghi ra một số nguyên duy nhất là số dư của kết quả tìm
được khi chia cho 123456789.

Ví dụ:

Input:
1
3

Output:
4
*/

package main

import "fmt"

const MOD = uint64(123456789)

func BinPow(base uint, exponent uint64) uint64 {

	if exponent == 0 {
		return 1
	}

	if exponent%2 == 0 {
		squareRooted := BinPow(base, exponent/2)
		return squareRooted * squareRooted % MOD
	}

	return uint64(base) * BinPow(base, exponent-1) % MOD
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var n uint64
		fmt.Scan(&n)

		fmt.Println(BinPow(2, n-1))
	}
}
