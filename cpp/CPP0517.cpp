#include <iomanip>
#include <iostream>
#include <string>

enum Gender { male, female };

struct NhanVien {
	size_t id;
	Gender gender;
	std::string name, birth, addr, reg_date;
	unsigned long long tax_id;
};

void nhap(NhanVien &nv) {

	static size_t id = 0;
	nv.id = ++id;

	std::string gender;
	for (std::string *s : { &nv.name, &gender, &nv.birth, &nv.addr }) {
		std::getline(std::cin >> std::ws, *s);
	}

	nv.gender = gender == "Nam" ? male : female;

	std::cin >> nv.tax_id;

	std::getline(std::cin >> std::ws, nv.reg_date);
}

void inds(NhanVien *ds, size_t size) {

	for (size_t i = 0; i < size; ++i) {
		std::cout << std::setw(5) << std::setfill('0') << ds[i].id << ' ';

		std::cout << ds[i].name << (ds[i].gender == male ? " Nam " : " Nu ") << ds[i].birth << ' '
				  << ds[i].addr << ' ';

		std::cout << std::setw(10) << ds[i].tax_id << ' ';

		std::cout << std::setw(0) << ds[i].reg_date << '\n';
	}

	std::cout.flush();
}

using std::cin;

int main() {
	struct NhanVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) nhap(ds[i]);
	inds(ds, N);
	return 0;
}
