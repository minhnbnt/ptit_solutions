#include <iostream>
#include <string>

class NhanVien {

	std::string ho_ten, gioi_tinh, dia_chi;
	std::string ngay_sinh, ngay_ki_hd;
	std::string ma_so_thue;
	unsigned ma_NV;

public:

	std::string maNV_str(void) {

		std::string str = std::to_string(ma_NV);
		while (str.length() < 5) str = '0' + str;

		return str;
	}

	friend void operator>>(std::istream &is, NhanVien &nv) {

		static bool is_input = true;

		if (!is_input) {

			std::cout << nv.maNV_str() << ' ' << nv.ho_ten << ' ' << nv.gioi_tinh;
			std::cout << ' ' << nv.ngay_sinh << ' ' << nv.dia_chi << ' ';
			std::cout << nv.ma_so_thue << ' ' << nv.ngay_ki_hd << '\n';

			return;
		}

		static unsigned ma = 0;
		nv.ma_NV = ++ma;

		std::getline(is, nv.ho_ten);
		is >> nv.gioi_tinh >> nv.ngay_sinh;
		std::getline(is >> std::ws, nv.dia_chi);
		is >> nv.ma_so_thue >> nv.ngay_ki_hd;

		is_input = false;
	}
};

using std::cin;

int main() {
	NhanVien a;
	cin >> a;
	cin >> a;
	return 0;
}
