class varTest:
    classVar = 100
    classVar1 = 200

    def __init__(self, a, b):
        self.instanceVar = a
        self.classVar = b

    def print(self):
        print("类的变量", varTest.classVar, varTest.classVar1)
        # classVar在实例里面名称和类中一致，实例创建了新的实例属性，隐藏了类属性
        print("通过实例引用", self.classVar, self.classVar1)
        print("类实例的变量", self.instanceVar, self.classVar)

class methodTest:
    count = 0

    def __init__(self):
        self.a = 1
        self.b = 2
        methodTest.count += 1

    @staticmethod
    def staticFunc():
        print("static method")

    @classmethod
    def classFunc(cls):
        print(cls.count)

if __name__ == "__main__":
    v = varTest(1,2)
    v.print()

    m = methodTest()
    methodTest.staticFunc()
    methodTest.classFunc()