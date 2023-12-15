/*
Cho mảng A[] gồm n số nguyên dương. Mảng A[] được gọi là mảng mục tiêu. Hãy tạo một mảng bắt đầu S[]
gồm n phần tử có các phần tử ban đầu được thiết lập là 0. Chỉ được phép thực hiện hai thao tác dưới
đây:

Thao tác 1 (Increament Operation): tăng giá trị của 1 phần tử bất kỳ lên 1 đơn vị.
Thao tác 2 (Double Operation ): nhân toàn bộ phần tử trong mảng với 2.
Hãy tìm số các ít nhất để dịch chuyển mảng bắt đầu S[] thành mảng mục tiêu A[].

Ví dụ với A[] = {16, 16, 16} ta cần thực hiện ít nhất 7 thao tác như sau:

Sử dụng 3 thao tác Increament để biến : S[0] =1, S[1]=1, S[2]=1.
Sử dụng 4 thao tác Double để biến : S[0] =16, S[1]=16, S[2]=16.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n; dòng tiếp theo là n số A[i] của mảng A[]; các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3; 1≤ A[i]  ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
3
16 16 16
2
2 3

Output:
7
4
*/

#include <stdio.h>

unsigned num_of_operators(unsigned *arr, unsigned ele) {

	unsigned increment = 0, multiple = 0;

	for (unsigned i = 0; i < ele; ++i) {

		unsigned exp = 0;
		unsigned num = arr[i];

		while (1) {

			if (num % 2 == 1) {
				++increment;
			}

			num /= 2;

			if (num == 0) break;

			++exp;
		}

		if (exp > multiple) {
			multiple = exp;
		}
	}

	return increment + multiple;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned ele, i;
		scanf("%u", &ele);

		unsigned arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%u", arr + i);
		}

		printf("%u\n", num_of_operators(arr, ele));
		fflush(stdout);
	}

	return 0;
}
