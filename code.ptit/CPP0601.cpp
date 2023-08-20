#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class SinhVien {
	float GPA;
	string HoTen, Lop, NgSinh;
public:
	void nhap(void) {

		getline(cin >> ws, this->HoTen);

		getline(cin >> ws, this->Lop);

		getline(cin >> ws, this->NgSinh);

		cin >> GPA;
	}

	void xuat(void) {

		string token;
		vector<string> vec_str;
		istringstream iss(this->NgSinh);

		while (getline(iss, token, '/')) {
			vec_str.push_back(token);
		}
		for (string *p : { &vec_str[0], &vec_str[1] })
			if (p->length() < 2) *p = '0' + *p;

		cout.precision(2);
		cout << "B20DCCN001 " << this->HoTen << ' ' << this->Lop << ' ';
		cout << vec_str[0] << '/' << vec_str[1] << '/' << vec_str[2];
		cout << ' ' << fixed << this->GPA << endl;
	}
};

int main() {
	SinhVien a;
	a.nhap();
	a.xuat();
	return 0;
}
