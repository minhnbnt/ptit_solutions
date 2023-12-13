#include <iostream>
#include <sstream>

void proper_date(std::string &date) {

	std::istringstream iss(date);
	date.clear();
	
	while (true) {

		std::string tmp;		
		std::getline(iss, tmp, '/');
		
		while (tmp.size() < 2) {
			tmp = '0' + tmp;
		}
		
		date += tmp;
		
		if (iss.eof()) {
			break;
		}
		
		date += '/';
	}
}

class SinhVien {
	
	std::string name, grade, birth;
	float GPA;
	
public:
	
	friend void operator>>(std::istream &is, SinhVien &sv) {
		
		for (std::string *s : { &sv.name, &sv.grade, &sv.birth }) {
			std::getline(is >> std::ws, *s);
		}
		
		proper_date(sv.birth);
		
		is >> sv.GPA;
	}
	
	friend void operator<<(std::ostream &os, const SinhVien &sv) {
		
		os.precision(2);
		
		os << "B20DCCN001 " << sv.name << ' ' << sv.grade << ' ';
		os << sv.birth << ' ' << std::fixed << sv.GPA << '\n';
	} 
};

using std::cin, std::cout;

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}
