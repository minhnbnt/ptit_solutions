number_of_sentences = int(input())

assert number_of_sentences % 2 == 0

sentences = [
    input().split()  #
    for _ in range(number_of_sentences)
]

sentence_lengths = [len(sentence) for sentence in sentences]

types = []

i = 0
while i < number_of_sentences:
    current_type = 1
    if len(sentences[i]) == 7:
        current_type = 2

    if current_type == 2:
        types.append(current_type)
        i += 4
        continue

    if len(types) == 0 or types[-1] == 2:
        types.append(current_type)

    i += 2

print(len(types), *types, sep="\n")
