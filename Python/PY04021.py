from datetime import datetime
class Time:
    H, M = "", ""
    def __init__(self, id, name, in_Time, out_Time):
        self.id = id
        self.name = name
        self.in_Time = in_Time
        self.out_Time = out_Time
        self.H = ((datetime.strptime(self.out_Time, "%H:%M") - (datetime.strptime(self.in_Time, "%H:%M"))).seconds // 3600)
        self.M = ((datetime.strptime(self.out_Time, "%H:%M") - (datetime.strptime(self.in_Time, "%H:%M"))).seconds // 60) % 60
        self.gg = float(self.H) + float(self.M / 60)
        
    def __str__(self):
        return f"{self.id} {self.name} {self.H} {'gio'} {self.M} {'phut'}"


if __name__ == '__main__':
    n = int(input())
    players = []

    for _ in range(n):
        id = input()
        name = input()
        in_Time = input()
        out_Time = input()
        x = Time(id, name, in_Time, out_Time)
        players.append(x)
    players.sort(key=lambda x : -x.gg)
    for player in players:
        print(player)


  