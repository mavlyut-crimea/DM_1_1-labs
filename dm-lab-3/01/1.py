n = int(input())
print(*[bin(i)[2:].zfill(n) for i in range(2 ** n)], sep = '\n')
