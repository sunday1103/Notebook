class basic:
    """This is the basic class"""
    classVar = 100

    def __init__(self, a, b):
        self.a = a
        self.b = b

    def print(self):
        print(self.a, self.b)

class derivedClass(basic):
    """Derived class"""

    def __init__(self, a, b):
        basic.__init__(self, a, b)
        print('obtain derived class')

if __name__ == "__main__":
    # basic class
    basicObj = basic(10,20)
    basicObj.print()
    print(basicObj.__doc__)
    # class and instance
    x1 = basic(10,20)
    x2 = basic(40,50)
    print(x1.a, x1.b)
    print(x2.a, x2.b)
    print(x1.classVar)
    print(x2.classVar)
    # derived class
    y = derivedClass(200,11)
    y.print()