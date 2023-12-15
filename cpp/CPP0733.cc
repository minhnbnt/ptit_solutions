/*
Cho ma trận A[N][M] chỉ bao gồm các số 0 và 1. Hãy tìm đường đi ngắn nhất từ một phần tử bắt đầu đến
phần tử đích. Biết mỗi bước đi ta chỉ được phép dịch chuyển từ phần tử có giá trị 1 đến phần tử có
giá trị 1. Ví dụ với ma trận dưới đây sẽ cho ta kết quả là 11.

A[9][10] = {{*1, 0,*1,*1,*1, 1, 0, 1, 1, 1 },
            {*1, 0,*1, 0, 1, 1, 1, 0, 1, 1 },
            {*1,*1,*1, 0, 1, 1, 0, 1, 0, 1 },
            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};

Begin = A[0][0];
End = A[3][4];

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: Dòng đầu tiên đưa vào 6 số N, M,
phần tử bắt đầu (x, y),  phần tử kết thúc (z, t) ; dòng tiếp là N×M các phần tử của ma trận A[][];
các phần tử được viết cách nhau một vài khoảng trống.
T, N, M, x, y, z, t thỏa mãn ràng buộc: 1≤T≤100; 1≤ N, M ≤10^3; 1≤ x, y, z, t ≤10^3.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Nếu không tìm được đáp án, in ra -1.
Input:
1
9 10 0 0 3 4
1 0 1 1 1 1 0 1 1 1
1 0 1 0 1 1 1 0 1 1
1 1 1 0 1 1 0 1 0 1
0 0 0 0 1 0 0 0 0 1
1 1 1 0 1 1 1 0 1 0
1 0 1 1 1 1 0 1 0 0
1 0 0 0 0 0 0 0 0 1
1 0 1 1 1 1 0 1 1 1
1 1 0 0 0 0 1 0 0 1

Output:
11
*/
