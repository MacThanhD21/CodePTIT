class Time:
    H, M = "", ""
    def __init__(self, id, name, in_Hour, in_Minute, out_Hour, out_Minute):
        self.id = id
        self.name = name
        self.in_Hour = in_Hour
        self.in_Minute = in_Minute
        self.out_Hour = out_Hour
        self.out_Minute = out_Minute
        
    def __str__(self):
        Time = (self.out_Hour - self.in_Hour) + (self.out_Minute - self.in_Minute) / 60
        H = Time[:1]
        M = str((Time) - H) * 60
        return f"{self.id} {self.name} {self.H} {self.M}"


if __name__ == '__main__':
    n = int(input())
    players = []

    for _ in range(n):
        id = input()
        name = input()
        in_Time = input()
        in_Hour = int(in_Time[:2])
        in_Minute = int(in_Time[3:])
        out_Time = input()
        out_Hour = int(out_Time[:2])
        out_Minute = int(out_Time[3:])
        
        x = Time(id, name, in_Hour, in_Minute, out_Hour, out_Minute)
        players.append(x)
        
    for player in players:
        print(player)


  