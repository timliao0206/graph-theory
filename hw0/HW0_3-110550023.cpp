n,a,b,c = map(int,input().split())

ans = ""

for i in range(n):
    ls = map(int,input().split())
    cnt = 0
    for it,x in enumerate(ls):
        if it == i:
            continue
        if x == 0:
            cnt += b
        elif x == 1:
            cnt += a
        else:
            cnt += c
    ans += str(x) + " "

print(ans)
