#Final1
class Shape:
    def __init__(self, name: str):
        self.name : str = name
    
    def area(self)->int:
        return 72
    
    def perimeter(self)->int:
        return 17

class Rectangle(Shape):
    def __init__(self, name: str, width: int, height: int):
        Shape.__init__(self,name)
        self.width : int = width
        self.height: int = height
    
    def area(self)->int:
        return self.width * self.height
    
    def perimeter(self)->int:
        return 2 * (self.width + self.height)

class Circle(Shape):
    def __init__(self, name: str, radius: int):
        Shape.__init__(self,name)
        self.radius: int = radius
    
    def area(self)-> int:
        return 3 * self.radius ** 2
    
    def perimeter(self)-> int:
        return 2 * 3 * self.radius

class Calculator:
    def __init__(self):
        print("Calculator Initialized")
    def add(self, num1: int, num2: int)-> int:
        return num1 + num2
    
    def subtract(self, num1: int, num2: int)-> int:
        return num1 - num2
    
    def multiply(self, num1: int, num2:int)->int:
        return num1 * num2
    
    def divide(self, num1: int, num2: int)-> int:
        if num2 != 0:
            return num1 / num2
        else:
            return -1
def main():
    rectangle: Rectangle     = Rectangle("Rectangle", 5, 3)

    circle: Circle = Circle("Circle", 4)

    print(rectangle.area())
    print(rectangle.perimeter())
    print(circle.area())
    print(circle.perimeter())

    calculator:Calculator = Calculator()

    print("Addition:") 
    print(calculator.add(10, 5))

    print("Subtraction:")
    print(calculator.subtract(10, 5))

    print("Multiplication:") 
    print(calculator.multiply(10, 5))

    print("Division:")
    print(calculator.divide(10, 5))

if __name__ == "__main__":
    main()