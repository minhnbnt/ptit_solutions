#!/usr/bin/env python3

"""
Một xâu nhị phân độ dài n được gọi là thuận nghịch hay đối xứng nếu đảo ngược
xâu nhị phân đó ta vẫn nhận được chính nó.

Cho số tự nhiên n (n nhập từ bàn phím).
Hãy viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n.
Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một khoảng trống.

Ví dụ với n = 4 ta tìm được 4 xâu nhị phân thuận nghịch như dưới đây.

0 0 0 0
0 1 1 0
1 0 0 1
1 1 1 1

Ví dụ:

Input:
4

Output:
0 0 0 0
0 1 1 0
1 0 0 1
1 1 1 1
"""


def allBitsString(length):
    bits = []

    def generator():
        if len(bits) == length:
            yield bits
            return

        for bit in [False, True]:
            bits.append(bit)
            yield from generator()

            bits.pop()

    yield from generator()


size = int(input())

lengthRequired, mod = divmod(size, 2)

for bitsStr in allBitsString(lengthRequired + mod):
    result = ""
    for bits in bitsStr:
        result += "1" if bits else "0"

    for bits in reversed(bitsStr):
        if len(result) == size:
            break

        result += "1" if bits else "0"

    print(*result)
