n = int(input())

a = [0] * n
used = [False] * n

def gen(p):
	if p == n:
		print(*a)
		return
	for i in range(1, n + 1):
		if not used[i - 1]:
			used[i - 1] = True
			a[p] = i
			gen(p + 1)
			used[i - 1] = False

gen(0)
