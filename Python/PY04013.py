from datetime import datetime
import math

class Rain:
    def __init__(self, id, name, st_Time, en_Time, rain_Quantity):
        self.id = id
        self.name = name
        self.st_Time = datetime.strptime(st_Time, "%H:%M")
        self.en_Time = datetime.strptime(en_Time, "%H:%M")
        self.rain_Quantity = rain_Quantity
        self.total_Time = (self.en_Time - self.st_Time).total_seconds() / 60
    def update(self, Time1, Time2):
        self.total_Time += (datetime.strptime(Time2, "%H:%M") - datetime.strptime(Time1, "%H:%M")).total_seconds() / 60
    def __str__(self):
        self.rain_Quantity = format(round((self.rain_Quantity / (self.total_Time / 60) * 100)) / 100, ".2f")
        
        return f'{self.id} {self.name} {self.rain_Quantity}'

dsRain = []
for i in range(int(input())):
    id = "T" + format(i + 1, "02d")
    name = input()
    st_Time, en_Time = input(), input()
    rain_Quantity = int(input())
    ok = True
    for x in dsRain:
        if x.name == name:
            ok = False
            x.rain_Quantity += rain_Quantity
            x.update(st_Time, en_Time)
            break
    if ok: dsRain.append(Rain(id, name, st_Time, en_Time, rain_Quantity))
        
for x in dsRain:
    print(x)

