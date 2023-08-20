/*
Một từ được hiểu là dãy các ký tự liên tiếp không chứa ký tự space, ‘\t’, ‘\n’,
Cho xâu ký tự S có các ký tự space, ‘\t’, ‘\n’, hãy đếm số các từ của S.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S được viết
trên một dòng. T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ length(S)≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
Print the number of words
Print the number of words present in the string

Output:
5
9
*/

#include <iostream>
#include <sstream>
#include <string>

auto main(void) -> int {

	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	unsigned cases;
	cin >> cases;

	while (cases--) {

		string buf, word;
		getline(cin >> ws, buf);

		istringstream iss(buf);
		unsigned word_count = 0;

		while (iss >> word) {
			++word_count;
		}

		cout << word_count << endl;
	}

	return 0;
}
