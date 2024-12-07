from typing import Optional

number_of_lines = int(input())

topic: Optional[str] = None
number_of_question = 0

for _ in range(number_of_lines):
    line = input()

    if topic is None:
        topic = line
        continue

    if len(line.strip()) == 0:
        print(f"{topic}: {number_of_question}")
        topic, number_of_question = None, 0
        continue

    number_of_question += 1

if topic is not None:
    print(f"{topic}: {number_of_question}")
