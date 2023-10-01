/*
Chính quyền thành phố Highland đã lên kế hoạch để sửa tuyến đường ven biển sau
khi được sửa chữa tạm thời. Tuyến đường có chiều dài bằng N, và hiện tại có M
chiếc đèn cao áp đang hoạt động. Tầm chiếu sáng của mỗi chiếc đèn là K, nghĩa là
tại vị trí X nếu được dựng đèn, nó sẽ chiếu sáng cho khu vực từ X – K tới X + K.

Các bạn hãy thử tính xem cần dựng thêm ít nhất bao nhiêu đèn để tuyến đường có
thể được chiếu sáng hoàn toàn?

Input:
Dòng đầu tiên là chiều dài của tuyến đường N (1 ≤ N ≤ 1000).
Tiếp theo là số lượng chiếc đèn đang hoạt động, M (M ≤ N).
Dòng tiếp theo chứa số nguyên K (0 ≤ K ≤ N).
Dòng cuối chứa M số nguyên, lần lượt là vị trí của những chiếc đèn đang có.

Output:
In ra một số nguyên là đáp án đáp án tìm được.

Ví dụ:
Input:
6
2
2
1 5

Output:
0

-----
Input:
15
3
10
1 2 3

Output:
1
*/

#include <stdio.h>

int main() {
	unsigned ele, i, j;
	scanf("%u", &ele);
	char dark[ele];
	for (i = 0; i < ele; i++) dark[i] = 1;
	unsigned ls, pos, range;
	scanf("%u%*c%u", &ls, &range);
	for (i = 0; i < ls; i++) {
		scanf("%u", &pos);
		unsigned start = pos - range - 1, end = pos + range - 1;
		if ((long)pos - range - 1 < 0) start = 0;
		if (end >= ele) end = ele - 1;
		for (j = start; j <= end; j++) dark[j] = 0;
	}
	unsigned result = 0;
	for (i = 0; i < ele; i++)
		if (dark[i]) {
			++result;
			unsigned end = i + range * 2;
			if (end >= ele) end = ele - 1;
			for (j = i; j <= end; j++) dark[j] = 0;
		}
	printf("%u\n", result);
	return 0;
}
