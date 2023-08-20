#include <iostream>

using namespace std;

class NhanVien {

	unsigned maNV;
	unsigned long long masoThue;
	string hoTen, gtinh, diaChi;
	string ngaySinh, ngayKiHD;
public:
	string maNV_str(void) {
		string str = to_string(maNV);
		while (str.length() < 5) str = '0' + str;
		return str;
	}

	friend istream &operator>>(istream &is, NhanVien &nv) {

		static unsigned id = 0;
		nv.maNV = ++id;

		getline(is >> ws, nv.hoTen);

		is >> ws >> nv.gtinh >> ws >> nv.ngaySinh;

		getline(is >> ws, nv.diaChi);
		is >> nv.masoThue >> ws >> nv.ngayKiHD;

		return is;
	}

	friend ostream &operator<<(ostream &os, NhanVien &nv) {

		os << nv.maNV_str() << ' ' << nv.hoTen << ' ' << nv.gtinh << ' '
		   << nv.ngaySinh << ' ' << ' ' << nv.diaChi << ' ' << nv.masoThue
		   << ' ' << nv.ngayKiHD << '\n';

		return os;
	}
};

int main() {
	NhanVien a;
	cin >> a;
	cout << a;
	return 0;
}
