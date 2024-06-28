#!/usr/bin/env python3

"""
Xâu ký tự str được gọi là xâu AB nếu mỗi ký tự trong xâu hoặc là ký tự ‘A’ hoặc
là ký tự ‘B’.

Ví dụ xâu str=”ABBABB” là xâu AB độ dài 6.
Nhiệm vụ của bạn là hãy liệt kê tất cả các xâu AB có độ dài n.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên n.

T, n thỏa mãn ràng buộc: 1≤T≤10; 1≤n≤10.

Output:
Đưa ra kết quả mỗi test theo từng dòng. Mỗi xâu cách nhau 1 khoảng trống.

Input:
2
2
3

Output:
AA AB BA BB
AAA AAB ABA ABB BAA BAB BBA BBB
"""

from typing import Iterator


def allABStrings(length: int) -> Iterator[str]:
    chars = []

    def generator():
        if len(chars) == length:
            yield "".join(chars)
            return

        for bit in ["A", "B"]:
            chars.append(bit)
            yield from generator()

            chars.pop()

    yield from generator()


cases = int(input())
for _ in range(cases):
    size = int(input())

    result = allABStrings(size)
    print(*result)
