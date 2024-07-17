/*
Trong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực
hiện phép cộng.
Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng cậu ta chép các con số một
cách không chính xác.
Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại.
Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

Input:
Có một dòng chứa hai số nguyên dương A và B ( 1 ≤ A, B ≤ 1 000 000).

Output:
In ra 2 số nguyên cách nhau một dấu cách, tổng nhỏ nhất và lớn nhất có thể nhận
được.

Ví dụ:

Test 1
Input:
11 25

Output:
36 37

-----
Test 2
Input:
1430 4862

Output:
6282 6292

-----
Test 3
Input:
16796 58786

Output:
74580 85582
*/

package main

import "fmt"

func GetDiff(number int) (int, int) {

	currentDiff := 1
	largerDiff, smallerDiff := 0, 0

	for ; number > 0; number /= 10 {

		switch number % 10 {
		case 5:
			largerDiff += currentDiff
		case 6:
			smallerDiff -= currentDiff
		}

		currentDiff *= 10
	}

	return largerDiff, smallerDiff
}

func main() {

	var a, b int
	fmt.Scan(&a, &b)

	largerSum, smallerSum := a+b, a+b

	largerDiff, smallerDiff := GetDiff(a)

	largerSum += largerDiff
	smallerSum -= smallerDiff

	largerDiff, smallerDiff = GetDiff(b)

	largerSum += largerDiff
	smallerSum -= smallerDiff

	fmt.Println(smallerSum, largerSum)
}
