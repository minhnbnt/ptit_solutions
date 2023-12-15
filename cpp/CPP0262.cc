/*
Cho hai số tự nhiên n, m. Nhiệm vụ của bạn là xác định xem có thể chia các số từ 1 đến n thành hai
tập sao cho giá trị tuyệt đối của tổng hai tập là m và tổng các phần tử của cả hai tập là các số
đồng nguyên tố (co-prime : nguyên tố cùng nhau) hay không? Ví dụ n =5, m = 7 ta có kết quả là Yes vì
ta chia thành 2 tập {1, 2, 3, 5} và 4 có giá trị tuyệt đối của tổng hai tập là 7 và là các số nguyên
tố cùng nhau. Với n=6, m=3 ta có câu trả lời là No vì ta có thể tìm ra hai tập {1, 2, 4, 5} và {3,
6} có trị tuyệt đối của tổng là 3 tuy nhiên cặp 12=1+2+4+5 và 9=3 + 6 không là đồng nguyên tố.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
T dòng tiếp đưa các bộ test. Mỗi bộ test được viết trên một dòng là bộ hai số n, m phân biệt nhau
bởi một vài khoảng trống.
Các số T, n, m, thỏa mãn ràng buộc: 1≤T≤100; 1≤n,m≤10^12;

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Input
2
5 7
6 3

Output
Yes
No
*/
