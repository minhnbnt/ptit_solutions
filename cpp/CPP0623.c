/*
Thông tin về mỗi sinh viên gồm:

Mã sinh viên: dãy ký tự không có khoảng trống (không quá 15). Đảm bảo không trùng nhau.
Họ và tên: độ dài không quá 100
Lớp: dãy ký tự không có khoảng trống (không quá 15)
Email: dãy ký tự không có khoảng trống (không quá 15)
Hãy nhập danh sách sinh viên và liệt kê sinh viên theo khóa học.
Chú ý: dữ liệu khóa học thể hiện qua hai chữ số thứ 2 và thứ 3 trong lớp sinh viên.

Input
Dòng đầu ghi số sinh viên (không quá 1000)
Mỗi sinh viên ghi trên 4 dòng lần lượt là: mã, họ tên, lớp, email.
Sau đó sẽ có giá trị số Q là số truy vấn
Tiếp theo là Q dòng, mỗi dòng ghi năm bắt đầu khóa học theo định dạng yyyy

Output
Với mỗi truy vấn, liệt kê danh sách sinh viên của khóa đó theo mẫu như trong ví dụ. Mỗi sinh viên
ghi trên một dòng, các thông tin cách nhau một khoảng trống. Thứ tự sinh viên vẫn giữ nguyên như thứ
tự ban đầu.

Ví dụ

Input
4
B16DCCN011
Nguyen Trong Duc Anh
D16CNPM1
sv1@stu.ptit.edu.vn
B15DCCN215
To Ngoc Hieu
D15CNPM3
sv2@stu.ptit.edu.vn
B15DCKT150
Nguyen Ngoc Son
D15CQKT02-B
sv3@stu.ptit.edu.vn
B15DCKT199
Nguyen Trong Tung
D15CQKT02-B
sv4@stu.ptit.edu.vn
1
2015

Output
DANH SACH SINH VIEN KHOA 2015:
B15DCCN215 To Ngoc Hieu D15CNPM3 sv2@stu.ptit.edu.vn
B15DCKT150 Nguyen Ngoc Son D15CQKT02-B sv3@stu.ptit.edu.vn
B15DCKT199 Nguyen Trong Tung D15CQKT02-B sv4@stu.ptit.edu.vn
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *id, *name, *grade, *email;
} Student;

char *input_str(void) {

	char *result;
	size_t pos = 0;

	getline(&result, &pos, stdin);
	strtok(result, "\n");

	return result;
}

void Student_input(Student *s) {

	s->id = input_str();
	s->name = input_str();
	s->grade = input_str();
	s->email = input_str();
}

void Student_print(const Student *s) {
	printf("%s %s %s %s\n", s->id, s->name, s->grade, s->email);
}

int main(void) {

	size_t ele, i;
	scanf("%zu%*c", &ele);

	Student arr[ele];
	for (i = 0; i < ele; ++i) {
		Student_input(arr + i);
	}

	unsigned cases;
	scanf("%u%*c", &cases);

	while (cases--) {

		char *buf = input_str();
		const size_t len = strlen(buf);

		printf("DANH SACH SINH VIEN KHOA %s:\n", buf);
		for (i = 0; i < ele; ++i) {

			if (buf[len - 2] != arr[i].grade[1] || buf[len - 1] != arr[i].grade[2]) {
				continue;
			}

			Student_print(arr + i);
		}
		fflush(stdout);

		free(buf);
	}

	for (i = 0; i < ele; ++i) {

		free(arr[i].id);
		free(arr[i].name);
		free(arr[i].grade);
		free(arr[i].email);
	}

	return 0;
}
