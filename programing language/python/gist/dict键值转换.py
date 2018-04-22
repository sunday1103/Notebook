a=[1,2,3,4]

b=['d','s','w','s']

c = dict(zip(a,b))

c
Out[21]: {1: 'd', 2: 's', 3: 'w', 4: 's'}

d = dict(zip(c.values(), c.keys()))

d
Out[23]: {'d': 1, 's': 4, 'w': 3}

d1 = {v:k for (k, v) in c.items()}

d1
Out[26]: {'d': 1, 's': 4, 'w': 3}
