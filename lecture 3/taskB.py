from math import log2

def set_kth_bit(n, k):
    mask = 1<<(k)
    n |= mask
    return n

def check_kth_bit(n, k):
    mask = 1<<(k)
    result = n & mask
    return (result != 0)

n = int(input())
result = [0]*n
a = [[0]*n for _ in range(n)]
for i in range(n):
    line = list(map(int, input().split()))
    for j in range(n):
        a[i][j] = line[j]

for i in range(n):
    for j in range(i, n):
        if(a[i][j]==0):
            continue
        for k in range(int(log2(a[i][j]))+1):
            if(check_kth_bit(a[i][j], k)):
                result[i] = set_kth_bit(result[i], k)
                result[j] = set_kth_bit(result[j], k)
for i in range(n):
    print(result[i], end=" ")



