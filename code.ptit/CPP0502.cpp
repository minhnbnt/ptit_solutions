#include <iomanip>
#include <iostream>

struct ThiSinh {

	std::string name, birth;

	float a, b, c;
};

void nhap(struct ThiSinh &A) {

	std::getline(std::cin >> std::ws, A.name);

	std::getline(std::cin >> std::ws, A.birth);

	std::cin >> A.a >> A.b >> A.c;
}

void in(const struct ThiSinh &A) {

	std::cout.precision(1);

	std::cout << A.name << ' ' << A.birth << ' ';
	std::cout << std::fixed << A.a + A.b + A.c << '\n';
}

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct ThiSinh A;
	nhap(A);
	in(A);
	return 0;
}
