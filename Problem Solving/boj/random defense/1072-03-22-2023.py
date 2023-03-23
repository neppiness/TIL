import math


def find_next(x, y, z):
    criteria = ((z + 1) * x - 100 * y) / (100 - z - 1)
    if math.ceil(criteria) == int(criteria):
        return int(criteria)
    else:
        return int(criteria) + 1


X, Y = map(int, input().split())
Z = int(Y / X * 100)

if Z > 98:
    print(-1)
else:
    print(find_next(X, Y, Z))