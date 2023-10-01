#include <iostream>
#include <string>

enum gender { male, female };

struct NhanVien {

	gender gtinh;

	std::string ten, nsinh, nkihd, dchi;

	unsigned long long msothue;
};

void nhap(struct NhanVien &a) {

	std::getline(std::cin >> std::ws, a.ten);

	a.gtinh = male;
	std::string gtinh;
	std::getline(std::cin >> std::ws, gtinh);
	if (gtinh == "Nu") {
		a.gtinh = female;
	} else if (gtinh != "Nam") {
		std::cerr << "Gioi tinh khong hop le!" << std::endl;
		abort();
	}

	std::getline(std::cin >> std::ws, a.nsinh);

	std::getline(std::cin >> std::ws, a.dchi);

	std::cin >> a.msothue;

	std::getline(std::cin >> std::ws, a.nkihd);
}

void in(const struct NhanVien &a) {

	std::cout << "00001 " << a.ten << ' ';
	std::cout << (a.gtinh == male ? "Nam " : "Nu ");

	std::cout << a.nsinh << ' ' << a.dchi << ' ' //
	          << a.msothue << ' ' << a.nkihd << '\n';
}

int main() {
	struct NhanVien a;
	nhap(a);
	in(a);
	return 0;
}
