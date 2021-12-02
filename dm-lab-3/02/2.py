n = int(input())
print(*[bin(i ^ i // 2)[2:].zfill(n) for i in range(2 ** n)], sep = '\n')
