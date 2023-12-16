class Athlete:
    def __init__(self, id, name, DOB, st_time, en_time):
        self.id = f"VDV{id:02d}"
        self.name = " ".join(name.title().split())
        self.DOB = DOB
        if self.DOB[1] == '/':
            self.DOB = '0' + self.DOB
        if self.DOB[4] == '/':
            self.DOB = self.DOB[:3] + '0' + self.DOB[3:]
        self.st_time = st_time
        self.en_time = en_time
    
    def get_real_time(self):
        data1 = self.st_time.split(":")
        start = int(data1[0]) * 3600 + int(data1[1]) * 60 + int(data1[2])
        
        data2 = self.en_time.split(":")
        end = int(data2[0]) * 3600 + int(data2[1]) * 60 + int(data2[2])
        
        return end - start
    
    def get_prio(self):
        Age = 2021 - int(self.DOB[-4:])
        if Age < 18:
            return 0
        elif Age < 25:
            return 1
        elif Age < 32:
            return 2
        else:
            return 3
    
    def get_result(self):
        return self.get_real_time() - self.get_prio()

    def __str__(self):
        real_time = self.get_real_time()
        prio = self.get_prio()
        result = self.get_result()
        
        return f"{self.id} {self.name} {real_time // 3600:02d}:{(real_time % 3600) // 60:02d}:{real_time % 60:02d} " \
               f"{prio // 3600:02d}:{(prio % 3600) // 60:02d}:{prio % 60:02d} " \
               f"{result // 3600:02d}:{(result % 3600) // 60:02d}:{result % 60:02d}"


n = int(input())
athletes = []

for i in range(n):
    id = i + 1
    athletes.append(Athlete(i + 1, input(), input(), input(), input()))

new_arr = sorted(athletes, key=lambda x: x.get_result())

rank_map = {new_arr[0].id: 1}

for i in range(1, len(new_arr)):
    if new_arr[i].get_result() == new_arr[i - 1].get_result():
        rank_map[new_arr[i].id] = rank_map[new_arr[i - 1].id]
    else:
        rank_map[new_arr[i].id] = i + 1

athletes.sort(key=lambda x: x.get_result())

for athlete in athletes:
    print(f"{athlete} {rank_map[athlete.id]}")
