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
