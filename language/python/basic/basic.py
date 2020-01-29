# 字符串格式化
a = 1
f'str{a}'
"str {}".format(a)
# 逻辑运算
a = True
b = False
print(f"a({a}) and b({b}):", a and b)
print("a({}) or b({})".format(a, b), a or b)
print("not a({})".format(a), not a)
# 位运算
a = 0b1100
b = 0b1000
# 二进制数输出位数和填充
print("a({:#06b}) & b({:#06b}) = {:#06b}".format(a, b, a & b))
print("a({:#06b}) | b({:#06b}) = {:#06b}".format(a, b, a | b))
print("~a({:#06b}) = {:#06b}".format(a, ~a))
print("a({:#06b}) ^ b({:#06b}) = {:#06b}".format(a, b, a ^ b))

# 基础控制 if for etc
word = ['a', 'b', 'tea']
for item in word:
    print(item)
for item in word.copy():
    if item == 'a':
        word.append('aa')

print(list(range(10)))


# else 语句
# 函数
def find_str(str1):
    for w in word:
        if item == str1:
            print('find')
            break
    else:
        print('not find')


find_str('a')
find_str('ss')

# 解包参数 * 和 **
a = [3,6]
# range接受2个参数，通过解包参数将a解包为3和6
range(*a)

def parrot(voltage, state='a stiff', action='voom'):
    print("-- This parrot wouldn't", action, end=' ')
    print("if you put", voltage, "volts through it.", end=' ')
    print("E's", state, "!")

d = {"voltage": "four million", "state": "bleedin' demised", "action": "VOOM"}
# 通过** 解包dict
parrot(**d)

# tuple
a = ([1,2], [3,4])

if __name__ == "__main__":
    print('exec by main')