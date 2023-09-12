

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

if __name__ == '__main__':
    arr = input().split()
    print(arr)
    r = Rectangle(int(arr[0]), int(arr[1]), str(arr[2]))
    print('{} {} {}'.format(r.perimeter(), r.area(), r.color()))