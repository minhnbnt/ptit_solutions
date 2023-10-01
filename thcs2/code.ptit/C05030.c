/*
Cho một ma trận điểm ảnh hình chữ nhật, kích thước N*M, được tô màu bởi 2 màu,
đánh số 1 hoặc 2. Giá trị 0 ứng với điểm ảnh chưa tô màu.

Một bộ ba điểm ảnh P1,P2,P3 (đã tô màu) được gọi là đẹp nếu thỏa mãn:

P1 và P2 cùng hàng. P2 và P3 cùng cột.
P1 và P3 cùng màu, khác với P2.
Hãy đếm số bộ ba điểm ảnh thỏa mãn tính chất trên.

Input
Dòng đầu ghi số bộ test.
Mỗi bộ test bắt đầu bằng hai số N, M (không quá 1000).
N dòng tiếp theo ghi trạng thái ma trận điểm ảnh, mỗi điểm ghi một trong 3 giá
trị: 0 hoặc 1 hoặc 2.

Output
Ghi ra số bộ ba điểm ảnh đẹp đếm được.

Ví dụ
Input:
1
3 3
000
201
002

Output:
1
*/
