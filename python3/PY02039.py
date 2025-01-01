rank = int(input())

matrix = []
for _ in range(rank):
    matrix.append([int(token) for token in input().split()])

required_diff = int(input())

upper_half_sum = sum(
    matrix[i][j]  #
    for i in range(rank)
    for j in range(i + 1, rank)
)

lower_half_sum = sum(
    matrix[i][j]  #
    for i in range(rank)
    for j in range(i)
)

diff = abs(upper_half_sum - lower_half_sum)

print("YES" if diff <= required_diff else "NO")
print(diff)
