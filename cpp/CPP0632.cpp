/*
Khai báo lớp Khách hàng với các thuộc tính:

Mã khách hàng: tự động tăng, tính từ KH001
Tên khách hàng: xâu ký tự độ dài không quá 50
Giới tính: Nam hoặc Nu
Ngày sinh: Theo đúng chuẩn dd/mm/yyyy
Địa chỉ: xâu ký tự độ dài không quá 100
Khai báo lớp Mặt hàng với các thuộc tính:

Mã mặt hàng: tự động tăng, tính từ MH001
Tên mặt hàng: xâu ký tự độ dài không quá 100
Đơn vị tính: xâu ký tự độ dài không quá 10
Giá mua: số nguyên dương không quá 7 chữ số
Giá bán: số nguyên dương không quá 7 chữ số
Khai báo lớp Hóa đơn là bạn của lớp Khách hàng và lớp Mặt hàng trong đó có các thông tin:

Mã hóa đơn
Mã khách hàng
Mã mặt hàng
Số lượng (không quá 1000)
Lợi nhuận
Viết chương trình nhập danh sách hóa đơn, sắp xếp theo lợi nhuận giảm dần và in danh sách ra màn
hình.

Input
Dòng đầu ghi số N là số khách hàng (không quá 20).
Tiếp theo là thông tin của N khách hàng, mỗi khách hàng ghi trên 4 dòng theo đúng thứ tự đã mô tả
(không có mã)
Dòng tiếp theo ghi số M là số mặt hàng (không quá 40).
Tiếp theo là thông tin của M mặt hàng, mỗi mặt hàng ghi trên 4 dòng theo đúng thứ tự đã mô tả (không
có mã)
Dòng tiếp theo ghi số K là số hóa đơn (không quá 100)
Mỗi hóa đơn ghi trên 1 dòng gồm 3 thông tin theo đúng thứ tự đã mô tả (không có mã và lợi nhuận).

Output
Ghi ra danh sách hóa đơn đã sắp xếp, trong đó gồm các thông tin sau, mỗi thông tin cách nhau đúng
một khoảng trống.

Mã hóa đơn
Tên khách hàng
Địa chỉ
Tên mặt hàng
Số lượng
Thành tiền
Lợi nhuận

Ví dụ
Input
2
Nguyen Van Nam
Nam
12/12/1997
Mo Lao-Ha Dong-Ha Noi
Tran Van Binh
Nam
11/14/1995
Phung Khoang-Nam Tu Liem-Ha Noi
2
Ao phong tre em
Cai
25000
41000
Ao khoac nam
Cai
240000
515000
3
KH001 MH001 2
KH001 MH002 3
KH002 MH002 4

Output
HD003 Tran Van Binh Phung Khoang-Nam Tu Liem-Ha Noi Ao khoac nam 4 2060000 1100000
HD002 Nguyen Van Nam Mo Lao-Ha Dong-Ha Noi Ao khoac nam 3 1545000 825000
HD001 Nguyen Van Nam Mo Lao-Ha Dong-Ha Noi Ao phong tre em 2 82000 32000
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using u64 = unsigned long long;

__always_inline std::string get_id(const char *head, unsigned id) {

	std::string result = std::to_string(id);
	while (result.length() < 3) result = '0' + result;

	return head + result;
}

class Customer {

	enum Gender { GENDER_male, GENDER_female };

	static std::unordered_map<std::string, const Customer *> map;

	std::string name, birth, addr;
	Gender gender;
	unsigned id;

public:

	friend class Bill;

	friend inline void operator>>(std::istream &is, Customer &cs) {

		static unsigned id = 0;
		cs.id = ++id;

		map.emplace(get_id("KH", id), &cs);

		std::getline(is >> std::ws, cs.name);

		std::string gender;
		std::getline(is >> std::ws, gender);

		static const std::unordered_map<std::string, Gender> map_gender = {
			{ "Nam", GENDER_male }, { "Nu", GENDER_female } //
		};

		cs.gender = map_gender.at(gender);

		std::getline(is >> std::ws, cs.birth);
		std::getline(is >> std::ws, cs.addr);
	}
};

class Item {

	static std::unordered_map<std::string, const Item *> map;

	std::string name, unit;
	u64 buy, sell;
	unsigned id;

public:

	friend class Bill;

	friend inline void operator>>(std::istream &is, Item &it) {

		static unsigned id = 0;
		it.id = ++id;

		map.emplace(get_id("MH", id), &it);

		std::getline(is >> std::ws, it.name);
		std::getline(is >> std::ws, it.unit);

		is >> it.buy >> it.sell;
	}
};

class Bill {

	const Customer *cs;
	const Item *it;
	u64 number;
	unsigned id;

public:

	inline u64 get_profit(void) const {
		const u64 profit_per_item = it->sell - it->buy;
		return profit_per_item * number;
	}

	inline u64 get_price(void) const {
		return it->sell * number;
	}

	inline bool operator<(const Bill &other) const {
		return this->get_profit() >= other.get_profit();
	}

	friend inline void operator>>(std::istream &is, Bill &bl) {

		static unsigned id = 0;
		bl.id = ++id;

		std::string id_cs, id_it;
		is >> std::ws >> id_cs >> id_it;

		bl.it = Item::map.at(id_it);
		bl.cs = Customer::map.at(id_cs);

		is >> bl.number;
	}

	friend inline void operator<<(std::ostream &os, const Bill &bl) {

		os << get_id("HD", bl.id) << ' ';

		os << bl.cs->name << ' ' << bl.cs->addr << ' ';

		os << bl.it->name << ' ' << bl.number << ' ';

		os << bl.get_price() << ' ' << bl.get_profit() << '\n';
	}
};

inline void sapxep(Bill *arr, size_t size) {
	std::sort(arr, arr + size);
}

std::unordered_map<std::string, const Item *> Item::map;
std::unordered_map<std::string, const Customer *> Customer::map;

// :))))))
using HoaDon = Bill;
using MatHang = Item;
using KhachHang = Customer;

using std::cin, std::cout;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	KhachHang dskh[25];
	MatHang dsmh[45];
	HoaDon dshd[105];
	int N, M, K, i;
	cin >> N;
	for (i = 0; i < N; i++) cin >> dskh[i];
	cin >> M;
	for (i = 0; i < M; i++) cin >> dsmh[i];
	cin >> K;
	for (i = 0; i < K; i++) cin >> dshd[i];

	sapxep(dshd, K);

	for (i = 0; i < K; i++) cout << dshd[i];
	return 0;
}
