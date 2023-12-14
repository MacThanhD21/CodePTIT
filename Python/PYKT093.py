import math
class Student:
    def __init__(self, id, name, d1, d2, d3):
        self.id = "SV" + format(id, "02d")
        self.name = " ".join(name.strip().title().split()) 
        self.tong_Diem = format(math.ceil((d1 * 3 + d2 * 3 + d3 * 2) / 8 * 100) / 100, ".2f")
    def __str__(self):
        return f'{self.id} {self.name} {self.tong_Diem}'
dsStu = []
for i in range(int(input())):
    dsStu.append(Student(i + 1, input(), float(input()), float(input()), float(input())))
dic = {}
dsStu.sort(key=lambda x : (-float(x.tong_Diem), x.id))
dic[dsStu[0].id] = 1
for i in range(1, len(dsStu)):
    if dsStu[i].tong_Diem == dsStu[i - 1].tong_Diem:
        dic[dsStu[i].id] = i
    else:
        dic[dsStu[i].id] = i + 1
for x in dsStu:
    print(x, dic[x.id])
    