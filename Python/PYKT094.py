
class PhongBan:
    def __init__(self, id, name):
        self.__id = id
        self.__name = name
        
    def getId(self):
        return self.__id
    
    def getName(self):
        return self.__name

class NhanVien:
    pb = ''
    def __init__(self, id, name, lcb, ngayCong, dsPB):
        self.__id = id
        self.__name = name
        self.__lcb = lcb * 1000
        self.__ngayCong = ngayCong
        for tmp in dsPB:
            if self.__id.endswith(tmp.getId()):
                self.pb = tmp.getName()
                break
            
    def getId(self):
        return self.__id
    
    def getName(self):
        return self.__name
    
    def getLcb(self):
        return self.__lcb
    
    def getngayCong(self):
        return self.__ngayCong
    
    def getHeSo(self):
        Gr = self.__id[0:1]
        soNamCongTac = int(self.__id[1:3])
        
        if Gr == 'A':
            if soNamCongTac >= 1 and soNamCongTac <= 3:
                return 10
            elif soNamCongTac >= 4 and soNamCongTac <= 8:
                return 12
            elif soNamCongTac >= 9 and soNamCongTac <= 15:
                return 14
            else:
                return 20
        elif Gr == 'B':
            if soNamCongTac >= 1 and soNamCongTac <= 3:
                return 10
            elif soNamCongTac >= 4 and soNamCongTac <= 8:
                return 11
            elif soNamCongTac >= 9 and soNamCongTac <= 15:
                return 13
            else:
                return 16
        elif Gr == 'C':
            if soNamCongTac >= 1 and soNamCongTac <= 3:
                return 9
            elif soNamCongTac >= 4 and soNamCongTac <= 8:
                return 10
            elif soNamCongTac >= 9 and soNamCongTac <= 15:
                return 12
            else:
                return 14
        else:
            if soNamCongTac >= 1 and soNamCongTac <= 3:
                return 8
            elif soNamCongTac >= 4 and soNamCongTac <= 8:
                return 9
            elif soNamCongTac >= 9 and soNamCongTac <= 15:
                return 11
            else:
                return 13
    
    def getMonthSalary(self):
        return self.__lcb * self.__ngayCong * self.getHeSo()
        
    def __str__(self) -> str:
        return f'{self.__id} {self.__name} {self.pb}{self.getMonthSalary()}'
    

if __name__ == '__main__':
    n = int(input())
    dsPB = []
    for _ in range(n):
        s = input().split()
        
        name = ""
        for i in range(1, len(s)):
            name += s[i] + " "
        name.strip()
        
        dsPB.append(PhongBan(s[0], name))
    
    m = int(input())
    dsNV = []
    
    for _ in range(m):
        id = input()
        name = input()
        lcb = int(input())
        ngayCong = int(input())
        
        x = NhanVien(id, name, lcb, ngayCong, dsPB)
        dsNV.append(x)
    
    for nv in dsNV:
        print(nv)    