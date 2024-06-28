#!/usr/bin/env python3

"""
Một xâu kí tự S = (s1, s2, .., sn) được gọi là xâu AB độ dài n nếu với mọi si∈S
thì si hoặc là kí tự A hoặc si là kí tự B.

Ví dụ xâu S = “ABABABAB” là một xâu AB độ dài 8.
Cho số tự nhiên N và số tự nhiên K (1≤K<N≤15 được nhập từ bàn phím),
hãy viết chương trình liệt kê tất cả các xâu AB có độ dài N chứa duy nhất một
dãy K kí tự A liên tiếp.

Dữ liệu vào chỉ có một dòng ghi hai số N và K.

Kết quả ghi ra màn hình theo khuôn dạng:

Dòng đầu tiên ghi lại số các xâu AB thỏa mãn yêu cầu bài toán;
Những dòng kế tiếp, mỗi dòng ghi lại một xâu AB thỏa mãn. Các xâu được ghi ra
theo thứ tự từ điển.

Ví dụ:

INPUT:
5 3

OUTPUT:
5
AAABA
AAABB
ABAAA
BAAAB
BBAAA
"""

from typing import Iterator


def allABStrings(length: int) -> Iterator[str]:
    chars = list()

    def generator():
        if len(chars) == length:
            yield "".join(chars)
            return

        for char in ("A", "B"):
            chars.append(char)
            yield from generator()

            chars.pop()

    return generator()


def isValid(s: str, aLength: int) -> bool:
    if "A" * (aLength + 1) in s:
        return False

    return "A" * aLength in s


length, aLength = map(int, input().split())

result = [
    string  #
    for string in allABStrings(length)
    if isValid(string, aLength)
]

print(len(result), *result, sep="\n")
