n = int(input())
buf = n
iterations = 0
for i in range(1, buf):
    if(i & (i - 1) == 0):
        iterations+=1
max_num = n
for i in range(iterations):
    last_digit = 1 & buf
    buf = buf >> 1
    buf |= last_digit<<(iterations-1)
    max_num = max(max_num, buf)
print(max_num)