/*
Thông tin về sinh viên gồm có:

1. mã sinh viên là số nguyên tự động tăng;
2. tên sinh viên;
3. điểm sinh viên là số thực gồm điểm môn A, môn B, môn C.

Viết chương trình thực hiện 3 chức năng:

1. thêm mới
2. cập nhật điểm theo mã sinh viên
3. hiển thị danh sách sinh viên theo tổng điểm tăng dần

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
8.5 .50 9.0
2
2
tran van nam
5.5 5.0 6.0
3

Output:
2
2
2 tran van nam 5.5 5.0 6.0
1 nguyen van hai 8.5 5.5 7.5
*/

// no stdio.h challenge :D

#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

#define MAX 100
#define MAX_NAME 100
#define enable_prompt 0

#ifndef stdin
extern struct _IO_FILE *stdin;
#endif // in linux, stdin is defined in stdio.h

typedef struct {
	unsigned id;
	int name[MAX_NAME];
	float a, b, c;
	double sum;
} student;

unsigned size = 0;

void add(student *);
void update(student *);

int cmp(const void *a, const void *b) {
	student *x = (student *)a, *y = (student *)b;
	return x->sum > y->sum;
}

int main(int argc, char *argv[]) {
	int choice;
	student s[MAX];
	setlocale(LC_ALL, "");
	if (enable_prompt)
		wprintf(L"1. Add number of students.\n"
		        "2. Update\n"
		        "3. Exit\n");
	while (1) {
		if (enable_prompt) wprintf(L"Enter your choice: ");
		wscanf(L"%d", &choice);
		if (choice == 1) add(s);
		else if (choice == 2) update(s);
		else if (choice == 3) break;
		else if (enable_prompt) //
			wprintf(L"Invalid choice.\n");
	}
	qsort(s, size, sizeof(student), cmp);
	for (unsigned i = 0; i < size; i++)
		wprintf(L"%u %ls %.1f %.1f %.1f\n", //
		        s[i].id, s[i].name, s[i].a, s[i].b, s[i].c);
	return 0;
}

void input(student *s, int mode) {
	getwchar();
	wchar_t *p;
	static unsigned index = 0;
	if (mode) s->id = ++index;
	if (enable_prompt) wprintf(L"Enter name: ");
	fgetws(s->name, MAX_NAME, stdin), wcstok(s->name, L"\n", &p);
	if (enable_prompt) wprintf(L"Enter marks: ");
	wscanf(L"%f %f %f", &s->a, &s->b, &s->c);
	s->sum = s->a + s->b + s->c;
}

void update(student *s) {
	unsigned i, index;
	if (enable_prompt) wprintf(L"Enter id: ");
	wscanf(L"%u", &index), wprintf(L"%u\n", index);
	for (i = 0; i < size; i++)
		if (s[i].id == index) {
			input(&s[i], 0);
			return;
		}
	if (enable_prompt) wprintf(L"Cannot find student.\n");
}

void add(student *s) {
	unsigned add, i;
	student *p = s + size;
	if (enable_prompt) //
		wprintf(L"Enter number of students to add: ");
	wscanf(L"%u", &add), wprintf(L"%u\n", add), size += add;
	if (size > MAX) {
		if (enable_prompt) //
			wprintf(L"Cannot add more students.\n");
		size -= add;
		return;
	}
	for (i = 0; i < add; i++) input(&p[i], 1);
}
