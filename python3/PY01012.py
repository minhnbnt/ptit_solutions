s1, s2 = input(), input()
position = int(input()) - 1

print(s1[:position] + s2 + s1[position:])
