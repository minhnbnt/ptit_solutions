#!/usr/bin/env python3

"""
Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA để thể hiện sự sảng
khoái.
Đôi khi cũng có thể gõ HAHAAAAA chẳng hạn cho thêm phần nhấn mạnh.

Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:

Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A
Không có hai chữ H nào liền nhau

Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA theo thứ tự từ điển.

Input:
Dòng đầu ghi số bộ test T (không quá 10)
Mỗi bộ test ghi độ dài N (2 <= N < 16)

Output
Với mỗi bộ test, ghi ra tất cả các xâu HAHA tìm được theo thứ tự từ điển, mỗi
xâu viết trên một dòng.

Ví dụ
Input
2
2
4

Output
HA
HAAA
HAHA
"""

from typing import Iterator


def allLaugh(length: int) -> Iterator[str]:
    current = []

    def generate() -> Iterator[str]:
        if len(current) == length:
            yield "".join(current)
            return

        for char in ["A", "H"]:
            current.append(char)

            yield from generate()

            current.pop()

    yield from generate()


def isValidLaugh(laugh: str) -> bool:
    for i in range(len(laugh) - 1):
        if laugh[i] == laugh[i + 1] == "H":
            return False

    return laugh[0] == "H" and laugh[-1] == "A"


cases = int(input())

for _ in range(cases):
    length = int(input())

    validLaughs = (
        laugh  #
        for laugh in allLaugh(length)
        if isValidLaugh(laugh)
    )

    for laugh in validLaughs:
        print(laugh)
