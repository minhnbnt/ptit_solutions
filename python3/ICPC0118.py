from datetime import date

cases = int(input())

for _ in range(cases):
    day, month = map(int, input().split())

    birthDay = date(2004, month, day)

    if birthDay >= date(2004, 12, 22):
        print("Ma Ket")

    elif birthDay >= date(2004, 11, 23):
        print("Nhan Ma")

    elif birthDay >= date(2004, 10, 23):
        print("Thien Yet")

    elif birthDay >= date(2004, 9, 23):
        print("Thien Binh")

    elif birthDay >= date(2004, 8, 23):
        print("Xu Nu")

    elif birthDay >= date(2004, 7, 23):
        print("Su Tu")

    elif birthDay >= date(2004, 6, 21):
        print("Cu Giai")

    elif birthDay >= date(2004, 5, 21):
        print("Song Tu")

    elif birthDay >= date(2004, 4, 20):
        print("Kim Nguu")

    elif birthDay >= date(2004, 3, 21):
        print("Bach Duong")

    elif birthDay >= date(2004, 2, 19):
        print("Song Ngu")

    elif birthDay >= date(2004, 1, 20):
        print("Bao Binh")

    else:
        print("Ma Ket")
