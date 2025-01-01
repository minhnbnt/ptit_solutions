from dataclasses import dataclass
from datetime import datetime


@dataclass
class Record:
    name: str
    phone_number: str
    date: datetime

    def get_last_name(self) -> str:
        return self.name.split()[-1]

    def __str__(self) -> str:
        return f"{self.name}: {self.phone_number} {self.date:%d/%m/%Y}"


records = []

with open("SOTAY.txt") as fp:
    lines = (line.strip() for line in fp)
    current_date = datetime.now()

    while True:
        try:
            line = next(lines)
        except StopIteration:
            break

        if line.startswith("Ngay "):
            current_date = datetime.strptime(line, "Ngay %d/%m/%Y")
            continue

        records.append(
            Record(
                name=line,
                phone_number=next(lines),
                date=current_date,
            )
        )

records.sort(key=lambda r: (r.get_last_name(), r.name))

with open("DIENTHOAI.txt", "w") as fp:
    for record in records:
        fp.write(f"{record}\n")
