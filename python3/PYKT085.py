from sys import stdin
from typing import Optional, Set

next(stdin)

topic: Optional[str] = None
questions: Set[str] = set()

results = dict()

for line in stdin:
    if topic is None:
        topic = line.strip()

    elif not line.strip():
        results[topic] = len(questions)
        topic, questions = None, set()

    else:
        questions.add(line)

if topic is not None:
    results[topic] = len(questions)

for topic, question_len in results.items():
    print(f"{topic}: {question_len}")
