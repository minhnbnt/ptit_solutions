/*
Cho mảng A[] gồm n số nguyên. Giá trị mỗi phần tử biểu diễn số lượng lớn nhất các bước ta có thể
dịch chuyển từ phần tử này. Phần tử có giá trị bằng 0 được hiểu ta không được phép dịch chuyển. Xuất
phát từ phần tử đầu tiên, hãy đếm số lượng ít nhất các bước dịch chuyển đến phần tử cuối cùng trong
mảng. Ví dụ với A[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} ta có câu trả lời là 3 tương ứng với các
phép dịch chuyển: 1 -> 3->8->9  (A[1] =1 nên ta dịch chuyển nhiều nhất 1 bước đến A[2]; A[2] = 3 nên
ta được phép dịch chuyển nhiều nhất 3 bước tương ứng với A[3]=5, A[4]=8, A[5] = 9; do A[4] = 8 nên
ta chỉ cần dịch chuyển 1 bước nữa là đến đích.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n; dòng tiếp theo là n số A[i] của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3; 1≤ A[i]  ≤10^7.

Output:
Đưa ra số bước dịch chuyển ít nhất của mỗi test, đưa ra -1 nếu ta không có phép dịch chuyển đến
đích.

Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7

Output:
3
2
*/
