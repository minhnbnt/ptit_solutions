#include <bits/stdc++.h>

using namespace std;

string abbveration(const string &s) {
	
	string result, tmp;
	istringstream iss(s);
	
	while (iss >> tmp) {
		result += toupper(tmp[0]);
	}
	
	return result;
}

string get_id(const char *head, size_t num, size_t len) {
	
	ostringstream oss;
	oss << setfill('0') << setw(len) << num;
	
	return head + oss.str();
}

class Teacher {
	
	string name, subject;
	size_t id;

public:

	void input(void);
	
	void print(void) const {
		
		cout << get_id("GV", id, 2) << ' ' << name;
		cout << ' ' << abbveration(subject) << '\n';
	}
};

unordered_map<string, vector<const Teacher *>> mp;

void Teacher::input(void) {
	
	static size_t id = 0;
	this->id = ++id;
	
	getline(cin >> ws, name);
	getline(cin >> ws, subject);
	
	const string abbr = abbveration(subject);
	
	auto it = mp.find(abbr);
	
	if (it != mp.end()) {
		it->second.push_back(this);
		return;
	}
	
	mp.emplace(abbr, vector<const Teacher *>());
	mp[abbr].push_back(this);
}

int main(void) {
	
	size_t i, num_teacher;
	cin >> num_teacher;
	
	auto ptr = make_unique<Teacher[]>(num_teacher);
	for (i = 0; i < num_teacher; ++i) {
		ptr[i].input();
	}
	
	unsigned cases;
	cin >> cases;
	
	while (cases-- > 0) {
		
		string subject;
		getline(cin >> ws, subject);
		
		const string abbr = abbveration(subject);
		
		cout << "DANH SACH GIANG VIEN BO MON " << abbr << ":\n";
		
		for (const Teacher *t : mp.at(abbr)) {
			t->print();
		}
	}
	
	return 0;
}
