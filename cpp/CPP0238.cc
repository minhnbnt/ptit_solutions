/*
Cho ma trận A[N][M] có các phần tử hoặc là ký tự ‘’O’’ hoặc là ký tự ‘’X’’. Hãy thay thế các miền
bao quanh ‘O’ bằng ‘X’. Một miền các ký tự ‘O’ bị bao quang bởi ký tự ‘X’ nếu các ký tự ‘X’ xuất
hiện ở phía dưới, phía trên, bên trái, bên phải các ký tự ‘O’. Ví dụ với ma trận dưới đây ta sẽ có
kết quả như sau:

X   X   X    X       X   X   X   X
X   O   X    X       X   X   X   X
X   O   O    X  -->  X   X   X   X
X   O   X    X       X   X   X   X
X   X   O    O       X   X   O   O

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: Dòng đầu tiên đưa vào hai số N, M ;
dòng tiếp là N×M các phần tử của ma trận A[][]; các phần tử được viết cách nhau một vài khoảng
trống.
T, N, M thỏa mãn ràng buộc: 1≤T≤100; 1≤ N, M ≤20.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
1 5
X O X O X
3 3
X X X
X O X
X X X

Output:
X O X O X
X X X
X X X
X X X
*/
