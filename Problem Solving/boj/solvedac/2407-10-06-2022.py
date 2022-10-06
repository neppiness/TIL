a = [1]*102
comb = list()
for i in range(0, 102):
    comb.append(a.copy())

for i in range(2, 101):
    for j in range(1, i):
        comb[i][j] = comb[i-1][j] + comb[i-1][j-1]

n, m = map(int, input().split())
print(comb[n][m])