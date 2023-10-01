#include <iosfwd>
#include <string>

void proper(std::string &s) {

	for (char &c : s) {
		c = tolower(c);
	}

	s[0] = toupper(s[0]);
}

class SinhVien {
	std::string name, grade, birth;
	float GPA;
public:
	friend std::istream &operator>>(std::istream &is, SinhVien &s);
	friend std::ostream &operator<<(std::ostream &os, const SinhVien &s);
};

#include <iostream>
#include <sstream>

std::istream &operator>>(std::istream &is, SinhVien &s) {

	std::string raw_name, raw_date, buf;

	for (std::string *s : { &raw_name, &s.grade, &raw_date }) {
		std::getline(is >> std::ws, *s);
	}
	is >> s.GPA;

	std::istringstream iss(raw_name);

	while (iss >> buf) {

		proper(buf);

		s.name += buf;

		if (iss.eof()) {
			break;
		}

		s.name += ' ';
	}

	iss = std::istringstream(raw_date);

	while (std::getline(iss, buf, '/')) {

		while (buf.length() < 2) buf = '0' + buf;

		s.birth += buf;

		if (iss.eof()) {
			break;
		}

		s.birth.push_back('/');
	}

	return is;
}

std::ostream &operator<<(std::ostream &os, const SinhVien &s) {

	os.precision(2);

	os << "B20DCCN001 " << s.name << ' ' << s.grade << ' ';
	os << s.birth << ' ' << std::fixed << s.GPA << '\n';

	return os;
}

using std::cin, std::cout;

int main() {
	SinhVien a;
	cin >> a;
	cout << a;
	return 0;
}
