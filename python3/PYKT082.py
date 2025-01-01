from math import floor


def compute_score(correct_count: int) -> float:
    if correct_count >= 39:
        return 9

    if correct_count >= 37:
        return 8.5

    if correct_count >= 35:
        return 8

    if correct_count >= 33:
        return 7.5

    if correct_count >= 30:
        return 7

    if correct_count >= 27:
        return 6.5

    if correct_count >= 23:
        return 6

    if correct_count >= 20:
        return 5.5

    if correct_count >= 16:
        return 5

    if correct_count >= 13:
        return 4.5

    if correct_count >= 10:
        return 4

    if correct_count >= 7:
        return 3.5

    if correct_count >= 5:
        return 3

    if correct_count >= 3:
        return 2.5

    return 0


def compute_overall_score(avg_score: float) -> float:
    decimal = floor(avg_score)
    floating = avg_score - decimal

    if floating < 0.25:
        return decimal

    elif floating < 0.75:
        return decimal + 0.5

    else:
        return decimal + 1


cases = int(input())

for _ in range(cases):
    tokens = input().split()

    reading = compute_score(int(tokens[0]))
    listening = compute_score(int(tokens[1]))

    speaking = float(tokens[2])
    writing = float(tokens[3])

    overall_score = compute_overall_score(
        (reading + listening + speaking + writing) / 4
    )

    print(f"{overall_score:.1f}")
