
from datetime import datetime
class Hotel:
    numbers_Day = 0
    Total_Mon = 0
    def __init__(self, id, name, id_Room, in_Date, ou_Date, Fee):
        self.id = "KH" + "{:02d}".format(id)
        self.name = name
        self.id_Room = id_Room
        self.in_Date = datetime(int(in_Date[6:]), int(in_Date[3:5]), int(in_Date[:2]))
        self.ou_Date = datetime(int(ou_Date[6:]), int(ou_Date[3:5]), int(ou_Date[:2]))
        self.Fee = int(Fee)
        self.numbers_Day = abs(self.in_Date - self.ou_Date).days + 1
        if self.id_Room[0] == '1':
            self.Total_Mon = (self.numbers_Day) * 25
        elif self.id_Room[0] == '2':
            self.Total_Mon = (self.numbers_Day) * 34
        elif self.id_Room[0] == '3':
            self.Total_Mon = (self.numbers_Day) * 50
        elif self.id_Room[0] == '4':
            self.Total_Mon = (self.numbers_Day) * 80
        self.Total_Mon += self.Fee

    def __str__(self):
        return f'{self.id} {self.name} {self.id_Room} {self.numbers_Day} {self.Total_Mon}'
dsCus = []
n = int(input())
for i in range(n):
    dsCus.append(Hotel(i + 1, input(), input(), input(), input(), input()))

dsCus.sort(key=lambda x: (-x.Total_Mon))

for x in dsCus:
    print(x)