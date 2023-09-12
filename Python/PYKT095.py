

from functools import cmp_to_key

class KhachHang:
    def __init__(self, ma, name, type, st, en):
        self.__ma = "KH" + format(ma, "02d")
        self.__name = name
        self.__type = type
        self.__en = en
        self.__st = st
    
    def chuanHoa(self):
        name = self.__name.split()
        self.__name = ' '.join(name).title()
    
    def calc1(self):
        type = self.__type
        soDien = (self.__en - self.__st)
        
        if type == 'A':
            if soDien < 100:
                return soDien * 450
            else:
                return 100 * 450
        elif type == 'B':
            if soDien < 500:
                return soDien * 450
            else:
                return 500 * 450
        elif type == 'C':
            if soDien < 200:
                return soDien * 450
            else:
                return 200 * 450
            
    def calc2(self):
        type = self.__type
        soDien = (self.__en - self.__st)
        
        if type == 'A':
            if soDien > 100:
                return (soDien - 100) * 1000
            else:
                return 0
        elif type == 'B':
            if soDien > 500:
                return (soDien - 500) * 1000
            else:
                return 0
        elif type == 'C':
            if soDien > 200:
                return (soDien - 200) * 1000
            else:
                return 0
            
    def getVat(self):
        return int(self.calc2() / 20)
    
    def totalMoney(self):
        return int(self.calc1() + self.calc2() + self.getVat())
     

    
    def __str__(self):
        self.chuanHoa()
        return f'{self.__ma} {self.__name} {self.calc1()} {self.calc2()} {self.getVat()} {self.totalMoney()}'

def compare_total_money(kh1, kh2):
    return kh2.totalMoney() - kh1.totalMoney()

if __name__ == '__main__':
    n = int(input())
    
    dsKH = []
    
    for i in range(n):
        name = input()
        res = input().split()
        kh = KhachHang(i + 1, name, res[0], int(res[1]), int(res[2]))
        
        kh.chuanHoa()
        dsKH.append(kh)
    
    dsKH.sort(key = cmp_to_key(compare_total_money))
    
    for x in dsKH:
        print(x)