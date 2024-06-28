#!/usr/bin/env python3

"""
Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là ‘A’, ‘E’,
còn lại là phụ âm.

Người ta muốn ghép các chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c (‘D’ <=
c <= ‘H’) sao cho mỗi chữ cái được sử dụng đúng một lần và xâu kết quả không có
nguyên âm nào bị kẹp giữa bởi hai phụ âm.

Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

Input
Chỉ có một dòng ghi chữ cái c (đảm bảo từ ‘D’ đến ‘H’).

Output
Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.

Ví dụ
Input
D

Output
ABCD
ABDC
ACBD
ACDB
ADBC
ADCB
BCDA
BDCA
CBDA
CDBA
DBCA
DCBA
"""

from itertools import permutations

VOWELS = {"A", "E", "I", "O", "U"}


def isValid(s) -> bool:
    for i in range(len(s) - 2):
        if s[i] in VOWELS:
            continue

        if s[i + 1] not in VOWELS:
            continue

        if s[i + 2] not in VOWELS:
            return False

    return True


beginChar = ord("A")
endChar = ord(input())

charsArray = [chr(i) for i in range(beginChar, endChar + 1)]

validString = (
    "".join(chars)  #
    for chars in permutations(charsArray)
    if isValid(chars)
)

for string in validString:
    print(string)
