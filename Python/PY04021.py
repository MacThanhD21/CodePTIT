class Time:
    def __init__(self, id, name, hours, minutes):
        self.__id = id
        self.__name = name
        self.__hours = hours
        self.__minutes = minutes

    def get_total_minutes(self):
        return self.__hours * 60 + self.__minutes

    def __str__(self):
        return f"{self.__id} {self.__name} {self.__hours} gio {self.__minutes} phut"


if __name__ == '__main__':
    n = int(input())
    players = []

    for _ in range(n):
        data = input().split()
        id = data[0]
        name = " ".join(data[1:-2])
        hours = int(data[-2])
        minutes = int(data[-1])
        player = Time(id, name, hours, minutes)
        players.append(player)

    players.sort(key=lambda x: x.get_total_minutes(), reverse=True)

    for player in players:
        print(player)


  