from collections import Counter

n = int(input())
cnt = Counter()
ls = map(int,input().split())
for x in ls:
	cnt[x] += 1
maxk,times = cnt.most_common(1)[0]

for key,val in cnt.most_common():
	if val < times:
		continue
	if maxk < key:
		maxk = key
print(maxk,times)