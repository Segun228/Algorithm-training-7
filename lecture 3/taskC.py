from math import log2
def count_ones(n):
    mask = 1
    counter = 0
    for _ in range(int(log2(n))+1):
        if((mask&n)!=0):
            counter+=1
        mask = mask<<1
    return counter

def analize_possibility(nums):
    total_counter = 0
    for num in nums:
        total_counter+=count_ones(num)
    return total_counter%2==0

n = int(input())
a = list(map(int, input().split()))
if(not (analize_possibility(a))):
    print("impossible")
    exit()
else:
    max_bit_length = max(a).bit_length()
    bin_a = [bin(num)[2:].zfill(max_bit_length) for num in a]
    result_bin = [list(num) for num in bin_a]
    column_ones_count = [0] * max_bit_length
    for num in result_bin:
        for i in range(max_bit_length):
            if(num[i] == '1'):
                column_ones_count[i] += 1
    for i in range(max_bit_length):
        if(column_ones_count[i] % 2 != 0):
            ones_indices = [j for j in range(n) if result_bin[j][i] == '1']
            if(len(ones_indices) >= 2):
                result_bin[ones_indices[0]][i] = '0'
                result_bin[ones_indices[1]][i] = '1'
            else:
                print("impossible")
                exit(0)
    result = [int(''.join(row), 2) for row in result_bin]
    print(*result)


