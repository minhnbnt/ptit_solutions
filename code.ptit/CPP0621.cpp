#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student {

	string id, grade;
	string name, email;

	student(string id, string name, string grade, string email)
	    : id(id), name(name), grade(grade), email(email) {}
};

int cmp(const student &a, const student &b) {
	return a.id < b.id;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<student> vec;

	while (!cin.eof()) {

		string id, grade;
		string name, email;

		cin >> ws >> id;

		getline(cin >> ws, name);

		cin >> ws >> grade >> ws >> email;

		vec.emplace_back(id, name, grade, email);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (const student &s : vec)
		cout << s.id << ' ' << s.name << ' ' //
		     << s.grade << ' ' << s.email << '\n';
	cout << flush;

	return 0;
}
