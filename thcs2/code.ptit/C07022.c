/*
Thông tin về sinh viên gồm có:

1. mã sinh viên là số nguyên tự động tăng;
2. tên sinh viên;
3. điểm sinh viên là số thực gồm điểm môn A, môn B, môn C.

Viết chương trình thực hiện 3 chức năng:

1. thêm mới
2. cập nhật điểm theo mã sinh viên
3. hiển thị danh sách các sinh viên có điểm 3 môn tăng dần (theo thứ tự xuất
hiện)

Input:
- Dòng thứ nhất là lựa chọn chức năng thực hiện
- Dòng thứ hai
 + Nếu lựa chọn ở dòng thứ nhất là 1 thì nhập số sinh viên sẽ thêm mới
 + Nếu lựa chọn ở dòng thứ nhất là 2 thì nhập mã sinh viên sẽ sửa đổi
- Dòng tiếp theo là thông tin sinh viên
Chức năng 3 cũng là kết thúc của luồng input

Output:
- Nếu lựa chọn là 1 thì in ra số sinh viên được thêm
- Nếu lựa chọn là 2 thì in ra mã sinh viên được sửa
- Nếu lựa chọn là 3 thì in ra danh sách theo mô tả dưới đây (các thông tin cách
nhau một khoảng trắng)

Ví dụ:
Input:
1
2
nguyen van hai
8.5 5.5 7.5
tran van tuan
8.5 6.5 9.0
2
2
tran van nam
5.5 6.0 7.0

Output:
3
2
2
2 tran van nam 5.5 6.0 7.0
*/

#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_NAME 100
#define enable_prompt 0

typedef struct {
	unsigned id;
	char name[MAX_NAME];
	float a, b, c;
} student;

unsigned size = 0;

void add(student *);
void update(student *);

int main(void) {
	student s[MAX];
	int choice;
	if (enable_prompt)
		puts("1. Add a number of students\n"
		     "2. Update a student\n"
		     "3. Exit");
	while (1) {
		if (enable_prompt) printf("Enter your choice: ");
		scanf("%d", &choice);
		if (choice == 1) add(s);
		else if (choice == 2) update(s);
		else if (choice == 3) break;
		else if (enable_prompt) //
			puts("Invalid choice");
	}
	for (unsigned i = 0; i < size; i++)
		if (s[i].a < s[i].b && s[i].b < s[i].c)
			printf("%u %s %.1f %.1f %.1f\n", //
			       s[i].id, s[i].name, s[i].a, s[i].b, s[i].c);
	return 0;
}

void input(student *s, int mode) {
	getchar();
	static unsigned index = 0;
	if (mode) s->id = ++index;
	if (enable_prompt) printf("Enter name: ");
	fgets(s->name, MAX_NAME, stdin), strtok(s->name, "\n");
	if (enable_prompt) printf("Enter marks: ");
	scanf("%f %f %f", &s->a, &s->b, &s->c);
}

void update(student *s) {
	char flag = 1;
	unsigned i, index;
	if (enable_prompt) printf("Enter id: ");
	scanf("%u", &index), printf("%u\n", index);
	for (i = 0; i < size; i++)
		if (s[i].id == index) //
			input(&s[i], 0), flag = 0;
	if (flag && enable_prompt) puts("Not found.");
}

void add(student *s) {
	unsigned add, i;
	student *p = s + size;
	if (enable_prompt) //
		printf("Enter number of students to add: ");
	scanf("%u", &add), printf("%u\n", add), size += add;
	if (size > MAX) {
		if (enable_prompt) //
			puts("Cannot add more students.");
		size -= add;
		return;
	}
	for (i = 0; i < add; i++) input(&p[i], 1);
}
