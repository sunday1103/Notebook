import re
import codecs

pattern = re.compile(r'\(.*?\)')

f = codecs.open('./file.txt', encoding='utf-8')
str = f.read()
result = pattern.findall(str)

count_frq = dict()
for one in result:
    if one in count_frq:
        count_frq[one] += 1
    else:
        count_frq[one] = 1

print(count_frq)

print(result)