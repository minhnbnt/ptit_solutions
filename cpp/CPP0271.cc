/*
Phương pháp làm mịn ảnh được thực hiện bằng cách sử dụng phép tích chập (convolution) giữa ma trận
ảnh và một ma trận kernel.

Cho ma trận ảnh đầu vào và kích thước L của ma trận kernel, nhiệm vụ của bạn là hãy in ra ma trận
ảnh sau khi được làm mịn.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test bắt đầu bởi hai số nguyên N, M và L (3 ≤ N,M ≤ 500; L ≤ min(n,m)). L được đảm bảo là một số
nguyên lẻ. Kế tiếp là N dòng, mỗi dòng gồm M số nguyên mô tả ma trận ảnh đầu vào, có giá trị trong
phạm vi từ 0 tới 255.

Output:

Với mỗi test, hãy in ra ma trận ảnh sau khi đã được làm mịn.

Ví dụ:
Input
2
4 4 3
2 1 0 0
3 2 1 1
4 5 2 1
2 2 9 0
3 3 3
1 2 3
4 5 6
7 8 9

Output
2 1
3 1
5

Giải thích test 1: Giá trị phần tử (1,1) = floor[(2+1+0+3+2+1+4+5+2) / 9] = floor [20/9] = 2.
*/
