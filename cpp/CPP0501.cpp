#include <complex>
#include <iomanip>
#include <iostream>

using namespace std;

struct Point {
	double x, y;
};

void input(struct Point &p) {
	cin >> p.x >> p.y;
}

double distance(const struct Point &p, const struct Point &q) {
	double x = p.x - q.x, y = p.y - q.y;
	return sqrt(pow(x, 2) + pow(y, 2));
}

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct Point A, B;
	int t;
	cin >> t;
	while (t--) {
		input(A);
		input(B);
		cout << fixed << setprecision(4) << distance(A, B) << endl;
	}
	return 0;
}
