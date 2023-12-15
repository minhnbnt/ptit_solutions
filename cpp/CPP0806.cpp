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
Khai báo lớp Hóa đơn trong đó có các thông tin:

Mã hóa đơn
Khách hàng
Mặt hàng
Số lượng (không quá 1000)
Viết chương trình nhập danh sách hóa đơn và in danh sách ra màn hình.

Input - có 3 file văn bản

File KH.in
Dòng đầu ghi số N là số khách hàng (không quá 20).
Tiếp theo là thông tin của N khách hàng, mỗi khách hàng ghi trên 4 dòng theo đúng thứ tự đã mô tả
(không có mã)

File MH.in
Dòng đầu ghi số M là số mặt hàng (không quá 40).
Tiếp theo là thông tin của M mặt hàng, mỗi mặt hàng ghi trên 4 dòng theo đúng thứ tự đã mô tả (không
có mã)

File HD.in
Dòng đầu theo ghi số K là số hóa đơn (không quá 100)
Mỗi hóa đơn ghi trên 1 dòng gồm 3 thông tin theo đúng thứ tự đã mô tả (không có mã).

Output

Ghi ra danh sách hóa đơn theo đúng thứ tự nhập, trong đó gồm các thông tin sau, mỗi thông tin cách
nhau đúng một khoảng trống.

Mã hóa đơn
Tên khách hàng
Địa chỉ
Tên mặt hàng
Đơn vị tính
Giá mua
Giá bán
Số lượng
Thành tiền
Ví dụ

Input
File KH.in
2
Nguyen Van Nam
Nam
12/12/1997
Mo Lao-Ha Dong-Ha Noi
Tran Van Binh
Nam
11/14/1995
Phung Khoang-Nam Tu Liem-Ha Noi

File MH.in
2
Ao phong tre em
Cai
25000
41000
Ao khoac nam
Cai
240000
515000

File HD.in
3
KH001 MH001 2
KH001 MH002 3
KH002 MH002 4

Output
HD001 Nguyen Van Nam Mo Lao-Ha Dong-Ha Noi Ao phong tre em Cai 25000 41000 2 82000
HD002 Nguyen Van Nam Mo Lao-Ha Dong-Ha Noi Ao khoac nam Cai 240000 515000 3 1545000
HD003 Tran Van Binh Phung Khoang-Nam Tu Liem-Ha Noi Ao khoac nam Cai 240000 515000 4 2060000
*/

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

std::string get_id(unsigned id, const char *head) {

	std::string result = std::to_string(id);
	while (result.length() < 3) {
		result = '0' + result;
	}

	return head + result;
}

struct Customer {

	static std::unordered_map<std::string, const Customer *> map;

	enum Gender { GENDER_male, GENDER_female };

	std::string name, birth, addr;
	unsigned id;
	Gender gen;

	inline void input(std::istream &is) {

		static unsigned id = 0;
		this->id = ++id;

		std::getline(is >> std::ws, name);

		std::string gender;
		std::getline(is >> std::ws, gender);

		static const std::unordered_map<std::string, Gender> map_gender = {
			{ "Nam", GENDER_male }, { "Nu", GENDER_female } //
		};

		std::getline(is >> std::ws, birth);
		std::getline(is >> std::ws, addr);

		map.emplace(get_id(id, "KH"), this);
	}
};

struct Item {

	static std::unordered_map<std::string, const Item *> map;

	std::string name, unit;
	unsigned long long buy, sell;
	unsigned id;

	inline void input(std::istream &is) {

		static unsigned id = 0;
		this->id = ++id;

		std::getline(is >> std::ws, name);
		std::getline(is >> std::ws, unit);

		is >> buy >> sell;

		map.emplace(get_id(id, "MH"), this);
	}
};

class Bill {

	std::string item_id, customer_id;
	unsigned long long number;
	unsigned id;

public:

	inline void input(std::istream &is) {

		static unsigned id = 0;
		this->id = ++id;

		is >> std::ws >> customer_id;
		is >> std::ws >> item_id;

		is >> number;
	}

	inline void print(std::ostream &os) const {

		const Item *it = Item::map.at(item_id);
		const Customer *cs = Customer::map.at(customer_id);

		const unsigned long long cost = it->sell * this->number;

		os << get_id(this->id, "HD") << ' ';

		os << cs->name << ' ' << cs->addr << ' ';

		os << it->name << ' ' << it->unit << ' ';
		os << it->buy << ' ' << it->sell << ' ';

		os << this->number << ' ' << cost;
	}
};

std::unordered_map<std::string, const Item *> Item::map;
std::unordered_map<std::string, const Customer *> Customer::map;

int main(void) {

	unsigned elekh, elemh, cases;

	std::ifstream ifs("KH.in");
	ifs >> elekh;

	std::vector<Customer> kh(elekh);
	for (Customer &cs : kh) {
		cs.input(ifs);
	}

	ifs = std::ifstream("MH.in");
	ifs >> elemh;

	std::vector<Item> mh(elemh);
	for (Item &it : mh) {
		it.input(ifs);
	}

	ifs = std::ifstream("HD.in");
	ifs >> cases;

	Bill hd;
	while (cases--) {

		hd.input(ifs);

		hd.print(std::cout);
		std::cout << std::endl;
	}

	return 0;
}
