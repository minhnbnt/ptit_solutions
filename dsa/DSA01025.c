/*
Vương quốc PTIT sử dụng bảng chữ cái gồm N chữ cái Latinh viết hoa.
Quy tắc đặt tên của gia đình Hoàng gia PTIT là chọn ra K chữ cái (không trùng
nhau) và sắp xếp lại theo thứ tự từ điển.

Hãy liệt kê tất cả các cái tên có thể có của gia đình Hoàng gia PTIT

Input
Dòng đầu ghi số bộ test T (không quá 10)
Mỗi bộ test ghi 2 số N và K (3 < K < N < 16)

Output
Với mỗi bộ test, ghi ra tất cả các cái tên có thể được tạo ra, mỗi kết quả viết
trên một dòng.

Ví dụ

Input:
1
4 2

Output:
AB
AC
AD
BC
BD
CD
*/

#include <stdio.h>

char *target;
size_t size = 0;

void generate_name(const char *begin, const char *end, size_t length) {

	if (size == length) {
		target[size] = '\0';
		puts(target);
		return;
	}

	while (begin != end) {

		target[size] = *begin;
		++begin, ++size;

		generate_name(begin, end, length);

		--size;
	}
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		size_t size, name_length;
		scanf("%zu%zu", &size, &name_length);

		char array[size], buf[name_length + 1];
		for (size_t i = 0; i < size; i++) {
			array[i] = 'A' + i;
		}

		target = buf;
		generate_name(array, array + size, name_length);
	}

	return 0;
}
