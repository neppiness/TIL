import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(sys.stdin.readline().rstrip())

def solve(cur, nxt, sz):
    if(sz == 1):
        print("%d %d\n" % (cur + 1, nxt + 1))
        return;
    tmp = 3 - (cur + nxt)
    solve(cur, tmp, sz - 1);
    print("%d %d\n" % (cur + 1, nxt + 1))
    solve(tmp, nxt, sz - 1);

ans = (1 << n) - 1
print("%d\n" % ans)
if(n <= 20):
    solve(0, 2, n)