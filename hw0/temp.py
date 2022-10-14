
n,a,b,c = map(int,input().split())

ans = [0 for i in range(n)]

for i in range(n):
    ls = map(int,input().split())
    for it,x in enumerate(ls):
        if it == i:
            continue
        if x == 0:
            ans[i] += b
        elif x == 1:
            ans[i] += a
        else:
            ans[i] += c

print(str(ans)[1:-1])