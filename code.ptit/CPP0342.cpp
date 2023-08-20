/*
Cho xâu ký tự S bao gồm các ký tự ‘A’,..,’Z’ và các chữ số ‘0’,...,’9’. Nhiệm vụ
của bạn in các ký tự từ ’A’,.., ‘Z’ trong S theo thứ tự anphabet và nối với tổng
các chữ số trong S ở cuối cùng.
Ví dụ S =”ACCBA10D2EW30” ta nhận được kết quả: “AABCCDEW6”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
AC2BEW3
ACCBA10D2EW30

Output:
ABCEW5
AABCCDEW6
*/

#include <cctype>
#include <iostream>
#include <set>
#include <string>

int main(void) {

	using namespace std;

	unsigned cases;
	cin >> cases;

	while (cases--) {

		string str;
		cin >> str;

		unsigned long long sum = 0;

		multiset<char> mset;
		for (const char &c : str) {
			if (isalpha(c)) {
				mset.insert(c);
				continue;
			}
			if (isdigit(c)) {
				sum += c - '0';
			}
		}

		for (const char &c : mset) cout.put(c);
		cout << sum << endl;
	}

	return 0;
}
