

class Car_Fee:
    def __init__(self, id_Car, type_Car, Num_vacancy, dir, date) :
        self.id_Car = id_Car
        self.type_Car = type_Car
        self.Num_vacancy = Num_vacancy
        self.dir = dir
        self.date = date
    
    def getDir(self):
        return self.dir
    
    def getDate(self):
        return self.date
    
    def getFee(self):
        if self.type_Car == 'Xe_con' and self.Num_vacancy == "5":
            return 10000
        elif self.type_Car == 'Xe_con' and self.Num_vacancy == "7":
            return 15000
        elif self.type_Car == 'Xe_tai':
            return 20000
        elif self.type_Car == 'Xe_khach' and self.Num_vacancy == "29":
            return 50000
        else:
            return 70000
    
    def __str__(self):
        return f''  

if __name__ == '__main__':
    n = int(input())
    a = []
    
    dic = {}
    sum = 0
    
    for i in range(n):
        s = input().split()
        
        a.append(Car_Fee(s[0], s[1], s[2], s[3], s[4]))
        
        if s[4] not in dic:
            dic[s[4]] = 1
    # for x in a:
    #     print(x.getDir())
    for key, value in dic.items():
        sum = 0
        for x in a:
            # print(key, x.getDate())
            if key == x.getDate():
                if x.getDir() == "IN":
                    # print(x.getFee())
                    sum += x.getFee()
        dic[key] = sum
    
    for key, value in dic.items():
        print(f"{key}: {value}")
        
    