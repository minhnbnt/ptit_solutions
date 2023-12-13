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

	inline void print(std::ofstream &os) {

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

		hd.print();
		std::cout << std::endl;
	}

	return 0;
}
