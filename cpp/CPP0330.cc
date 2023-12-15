/*
Cho số nguyên dương gồm N chữ số. Bạn chỉ được phép thực hiện hai thao tác:
Thao tác A: loại bỏ tất cả các chữ số giống nhau.
Thao tác B: sắp đặt lại vị trí các chữ số.

Hãy tìm số nguyên đối xứng lớn nhất có thể được tạo ra bằng cách thực hiện hai thao tác A hoặc B ở
trên. Ví dụ với số N = 1122233300000998, ta có thể tạo ra số đối xứng lớn nhất là 910000019 bằng
cách thực hiện các thao tác A, B như sau:

Thao tác A: loại bỏ các chữ số 2 ta nhận được số 1133300000998.
Thao tác A: loại bỏ các chữ số 3 ta nhận được số 1100000998.
Thao tác A: loại bỏ các chữ số 8 ta nhận được số 110000099.
Thao tác B: sắp đặt lại các số còn lại 110000099 để được số 910000019.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên dương có N chữ số.
T, N thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤1000.

Output:
Đưa ra số nguyên lớn nhất được tạo ra bởi thao tác A, B của mỗi test theo từng dòng.

Input:
5
12345000
11233300000998
3335
333566

Output:
5
910000019
333
63336
*/
