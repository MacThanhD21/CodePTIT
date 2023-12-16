from math import *
from collections import defaultdict
from itertools import combinations,permutations
from datetime import datetime

dic = defaultdict(int)
class Players:
    def __init__(self, id, name, name_Team, ns, height, pos):
        self.id = ''.join(x[0] for x in pos.split()) + format(id, "02d")
        self.name = name
        self.name_Team = name_Team
        self.ns = ns
        if self.ns[1] == '/':
            self.ns = '0' + self.ns
        if self.ns[4] == '/':
            self.ns = self.ns[:3] + '0' + self.ns[3:]
        self.res = self.ns[6:] + self.ns[3:5] + self.ns[:2]
        self.height = height
        self.pos = pos
    def __str__(self):
        return f'{self.id} {self.name} {self.name_Team} {self.ns} {self.height} {self.pos}'

dsPlayers = []

for i in range(1, int(input()) + 1):
    name = input()
    name_Team = input()
    ns = input()
    height = input()
    pos = input()
    vt = ''.join(x[0].upper() for x in pos.split())
    dic[vt] += 1
    dsPlayers.append(Players(dic[vt], name, name_Team, ns, height, pos))
    
dsPlayers.sort(key=lambda x: (-int(x.res), x.height))

for x in dsPlayers:
    print(x)