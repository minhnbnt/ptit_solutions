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
			{ "Nam", GENDER_male }, { "Nu", GENDER_female }  //
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

using HoaDon = Bill;
using MatHang = Item;
using KhachHang = Customer;

using std::cin, std::cout;

int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];

    sapxep(dshd, K);

    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}
