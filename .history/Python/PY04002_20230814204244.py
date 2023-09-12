class Rectangle:
    def __init__(self, width, length, color):
        self.__width = width
        self.__length = length
        self.__color = color
    
    def perimeter(self):
        return 2 * (self.__width + self.__length)
    
    def area(self):
        return self.__width * self.__length
    
    def color(self):
        return self.__color.title()

arr = input().split()
if(len(arr) == 3):
    l = int(arr[0])
    w = int(arr[1])
    c = (arr[2])
    r = Rectangle(l, w, c)
    if l > 0 and r > 0:
        print('{} {} {}'.format(r.perimeter(), r.area(), r.color()))
    else:
        print('INVALID')
else:
    print("INVALID")

