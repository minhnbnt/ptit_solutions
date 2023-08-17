/*
Trong những năm gần đây, hình thức thi trắc nghiệm được sử dụng phổ biến trong
kỳ thi Trung học phổ thông quốc gia. Ưu điểm của hình thức thi trắc nghiệm là có
thể chấm tự động hoàn toàn mà không cần sự can thiệp của con người, điều này đảm
bảo tính khách quan và chính xác. Giả sử có 2 mã đề thi 101 và 102 có các đáp án
được cho trong bảng dưới đây:

Câu    Đề 101   Đề 102
1        A        A
2        B        C
3        B        C
4        A        A
5        D        B
6        C        C
7        C        D
8        A        D
9        B        B
10       D        B
11       C        C
12       C        D
13       A        D
14       B        B
15       D        B

Nhiệm vụ của bạn là chấm điểm cho bài thi của các thí sinh trong một phòng thi.
Điểm thi được chấm trên thang điểm 10, làm tròn đến 2 chữ số phần thập phân.

Input:
Dòng đầu tiên đưa vào số bài thi T.

Các dòng tiếp theo mỗi đưa vào mã đề thi và các đáp án làm bài của thí sinh cách
nhau bởi một khoảng trống. Giả sử tất cả các đáp án đều được điền đầy đủ.

T thỏa mãn điều kiện 0 < T <= 1000

Output:
Điểm thi được làm tròn đến hai chữ số phần thập phân.

Input:
1
101 A B B A D C C A B D C C A B D

Output:
10.00
*/

#include <iomanip>
#include <iostream>
#include <unordered_map>

static std::unordered_map<int, const char *> rignt_ans = { //
	{ 101, "ABBADCCABDCCABD" },
	{ 102, "ACCABCDDBBCDDBB" }
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int id, pos;
		std::cin >> id;

		float score = 10;
		static const float score_per_ques = score / 15;

		for (int i = 0; i < 15; i++) {

			char ans;
			std::cin >> std::ws >> ans;

			if (ans != rignt_ans[id][i]) {
				score -= score_per_ques;
			}
		}

		std::cout << std::fixed << std::setprecision(2) << score << std::endl;
	}

	return 0;
}
