# Định nghĩa một decorator đơn giản
def my_decorator(func):
    def wrapper():
        print("Something is happening before the function is called.")
        func()
        print("Something is happening after the function is called.")
    return wrapper

# Sử dụng decorator cho một hàm
@my_decorator
def say_hello():
    print("Hello!")

@my_decorator
def say_goodbye():
    print("goodBye!")
    
# Gọi hàm đã được trang bị decorator
say_hello()
say_goodbye()
