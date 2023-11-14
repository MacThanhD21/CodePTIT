
class Student:
    def __init__(self, name, date, d1, d2, d3):
        self.name = name
        self.date = date
        self.d1 = d1
        self.d2 = d2
        self.d3 = d3
    def __str__(self) -> str:
        return f'{self.name} {self.date} {format(self.d1 + self.d2 + self.d3, ".1f")}'

ds = []
while True:
    try :
        name = input()
        date = input()
        d1 = float(input())
        d2 = float(input())
        d3 = float(input())
        student = Student(name, date, d1, d2, d3)
        ds.append(student)
    except EOFError:
        break
for x in ds:
    print(x)