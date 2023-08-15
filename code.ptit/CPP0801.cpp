#include <fstream>

int main(void) {

	std::ifstream ifs("PTIT.in");
	std::ofstream ofs("PTIT.out");

	std::string buf;

	while (std::getline(ifs, buf)) {
		ofs << buf << std::endl;
	}

	return 0;
}
