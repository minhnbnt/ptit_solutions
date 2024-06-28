#!/usr/bin/python3

"""
Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K.

Hãy viết chương trình liệt kê tất cả các dãy con của dãy số A[] sao cho tổng các
phần tử trong dãy con đó đúng bằng K.

Dữ liệu vào trên bàn phím (n=5, K=50), 5 số dòng thứ 2 là các phần tử dãy A:

5 50
5 10 15 20 25

Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:

Mỗi dòng ghi lại một dãy con. Hai phần tử khác nhau của dãy con được viết
cách nhau bởi một khoảng trống.

Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.
10 15 25
5 20 25
5 10 15 20
3
"""


def allValidSubarray(array, targetSum):
    validArray = []
    arrayLength = len(array)

    def solve(index=0, sum=0):
        if sum == targetSum:
            yield validArray

        if index == arrayLength:
            return

        for i in range(index, arrayLength):
            validArray.append(array[i])
            sum += array[i]

            yield from solve(i + 1, sum)

            validArray.pop()
            sum -= array[i]

    yield from solve()


size__, targetSum = (int(token) for token in input().split())
array = [int(token) for token in input().split()]

outputs = []
for validArray in allValidSubarray(array, targetSum):
    line = " ".join(str(element) for element in validArray)
    outputs.append(line)

for outputLine in reversed(outputs):
    print(outputLine)

print(len(outputs))
