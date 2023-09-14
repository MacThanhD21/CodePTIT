

import math

class Score:
    def __init__(self, id, name, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10) :
        self.__id = id
        self.__name = name
        self.__d1 = d1
        self.__d2 = d2
        self.__d3 = d3
        self.__d4 = d4
        self.__d5 = d5
        self.__d6 = d6
        self.__d7 = d7
        self.__d8 = d8
        self.__d9 = d9
        self.__d10 = d10
    
        

if __name__ == '__main__':
    
    n = int(input())
    
    arr = []
    for i in range(n) :
        name = input()
        Scores = [float(x) for x in input().split()]
        x = Score(i + 1, name, Scores[0], Scores[1], Scores[2], Scores[3], Scores[4], Scores[5], Scores[6], Scores[7], Scores[8], Scores[9], Scores[10])
    
    for Score in arr:
        print(Score)    