

class PhongBan:
    def __init__(self, id, name):
        self.id = id
        self.name = name

class Salary:
    def __init__(self, ma, name, base_salary, date, phongBan, heSo):
        self.__ma = ma
        self.__name = name
        self.__base_salary = base_salary
        self.__date = date
        self.__phongBan = phongBan
        self.__heSo = heSo


    def getPhongBan(self, dsPB):
        for tmp in dsPB:
            if self.ma.endswith(tmp.id):
                return tmp.name
    def getHeSo(self):
        return int(self.ma[1:3])

    def getSalary(self):
        return self.base_salary * self.date * self.getHeSo()

if __name__ == '__main__':
    t1= int(input())
    dsPB = []
    while t1 > 0:
        t1 -= 1
        arr = input().split()
        dsPB.append(PhongBan(arr[0], arr[1]))

    t2 = int(input())

    dsNV = []

    while t2 > 0:
        t2 -= 1
        ma = input()
        name = input()
        base_salary = int(input())
        date = int(input())
        s = Salary(ma, name, base_salary * 1000, date, '', 0)
        phongBan = s.getPhongBan(dsPB)
        dsNV.append(s)
        t2 -= 1

    for sv in dsNV:
        print(sv)


