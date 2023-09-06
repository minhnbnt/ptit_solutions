#include <algorithm>
#include <iostream>
#include <string>

struct SinhVien {

	float scores[3];
	std::string id, name, grade;

	void print(void) const {

		static size_t id = 0;

		std::cout << ++id << ' ' << this->id << ' ' << name;
		std::cout << ' ' << grade << std::fixed;

		for (const float &score : scores) {
			std::cout << ' ' << score;
		}

		std::cout.put(0xa);
	}
};

void nhap(SinhVien &sv) {

	for (std::string *s : { &sv.id, &sv.name, &sv.grade }) {
		std::getline(std::cin >> std::ws, *s);
	}

	for (float &score : sv.scores) {
		std::cin >> score;
	}
}

void sap_xep(SinhVien *ds, const size_t &size) {

	static auto comparator = [](const SinhVien &s1, const SinhVien &s2) {
		return s1.id < s2.id;
	};

	std::sort(ds, ds + size, comparator);
}

void in_ds(const SinhVien *ds, const size_t &size) {

	std::cout.precision(1);

	for (size_t i = 0; i < size; ++i) {
		ds[i].print();
	}

	std::cout.flush();
}

using std::cin;

int main() {
	int n;
	cin >> n;
	struct SinhVien *ds = new SinhVien[n];
	for (int i = 0; i < n; i++) {
		nhap(ds[i]);
	}
	sap_xep(ds, n);
	in_ds(ds, n);
	return 0;
}
