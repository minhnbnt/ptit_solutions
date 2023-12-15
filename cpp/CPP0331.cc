/*
Cho xâu ký tự S bao gồm các chữ số. Xâu S được gọi là Sum String nếu tồn tại một số tự nhiên k>2 sao
cho ta có thể chia xâu S thành k xâu con khác nhau S =(S1, S2, ..Sk) sao cho các số được tạo bởi các
xâu con thỏa mãn điều kiện  Si=Si-1 + Si-2 (i=3, 4, .., k). Ví dụ xâu S =”123415538” là một Sum
String vì tồn tại số k = 3 để phân tích xâu S thành 3 xâu con S = (“123”, “415”,”538”) thỏa mãn 123
+ 414 = 538. Tương tự như vậy xâu S=”12345” không phải là một Sum String.

Hãy kiểm tra xem S có phải là xâu Sum String hay không?

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các test. Mỗi test là một xâu ký tự số S.
T và S thỏa mãn ràng buộc 1≤T≤100, 3≤length(S)≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
3
123415538
12345
1122335588143

Output:
Yes
No
Yes
*/
