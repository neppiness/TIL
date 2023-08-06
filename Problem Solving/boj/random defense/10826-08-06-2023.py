p = [];
p.append(0);
p.append(1);

for i in range(2, 10001):
    p.append(p[i - 1] + p[i - 2]);

b = int(input());
print(p[b]);