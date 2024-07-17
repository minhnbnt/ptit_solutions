#!/usr/bin/env python3

"""
Nam có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. Không có 2 thẻ nào ghi hai
số trùng nhau. Nam muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào
liền kề nhau ở cạnh nhau.

Ví dụ với N = 4 thì cách xếp 3142 là hợp lệ nhưng cách xếp 1324 không hợp lệ.

Hãy giúp Nam liệt kê tất cả các cách xếp thỏa mãn theo thứ tự từ điển.

Input
Dòng đầu ghi số bộ test T (không quá 10)
Mỗi bộ test ghi số N (3 < N < 10)

Output
Với mỗi bộ test, ghi ra tất cả các cách xếp thứ tự thỏa mãn, mỗi cách trên một
dòng.

Ví dụ
Input
1
4

Output
2413
3142
"""

from itertools import permutations


def isValid(digits) -> bool:
    for i in range(1, len(digits)):
        if abs(digits[i] - digits[i - 1]) < 2:
            return False

    return True


cases = int(input())

for _ in range(cases):
    size = int(input())
    digits = [i + 1 for i in range(size)]

    validNumbers = (
        "".join(map(str, permutation))
        for permutation in permutations(digits)
        if isValid(permutation)
    )

    for number in validNumbers:
        print(number)
