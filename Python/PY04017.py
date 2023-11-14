import math
# dm: không được để round luôn lúc trả về vì tý sort nó bị mất mát giá trị => sai
class Cyclist:
    def __init__(self, id, name, unit, finish_time):
        self.id = id
        self.name = name
        self.unit = unit
        self.finish_time = finish_time

    def average_speed(self):
        res = self.finish_time.split(':')
        return (120 / (int(res[0]) - 6 + int(res[1]) / 60))

    def __str__(self):
        return f'{self.id} {self.name} {self.unit} {round(self.average_speed())} Km/h'

n = int(input())
cyclists = []
for _ in range(n):
    name = input()
    unit = input()
    finish_time = input()
    id = ''.join(word[0] for word in unit.split() + name.split())
    cyclists.append(Cyclist(id, name, unit, finish_time))

cyclists.sort(key=lambda cyclist: -cyclist.average_speed())
for cyclist in cyclists:
    print(cyclist)