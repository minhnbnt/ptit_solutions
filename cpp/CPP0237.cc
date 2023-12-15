/*
Cho ma trận vuông A[N][N] có các phần tử hoặc là ký tự ‘O’ hoặc là ký tự ‘X’. Hãy tìm cấp của ma
trận vuông lớn nhất có các phần tử ‘X’ bao quanh các phần tử ‘O’. Ví dụ với ma trận dưới đây ta sẽ
có kết quả là 3.

X   O   X   X   X
X  *X  *X  *X   X
X  *X   O  *X   O
X  *X  *X  *X   X
X   X   X   O   O

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: Dòng đầu tiên đưa vào số N ; dòng
tiếp là N×N các phần tử của ma trận A[][]; các phần tử được viết cách nhau một vài khoảng trống.
T, N thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤20.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
2
X X
X X
4
X X X O
X O X X
X X X O
X O X X

Output:
2
3
*/
