def add(index: int, diff: int, fenwick_list: list):
    while(index < len(fenwick_list)):
        fenwick_list[index] += diff
        index = index | (index + 1)

def set_value(index: int, new_value: int, original_list: list, fenwick_list: list):
    diff = new_value - original_list[index]
    original_list[index] = new_value
    add(index, diff, fenwick_list)

def prefix_sum(index: int, fenwick_list: list)->int:
    result = 0
    while(index >= 0):
        result+=fenwick_list[index]
        index = fenwick_function(index) - 1
    return result

def fenwick_function(index: int) -> int:
    return (index & (index + 1))

def interval_sum(left: int, right: int, fenwick_list : list):
    return prefix_sum(right, fenwick_list) - prefix_sum(left-1, fenwick_list)


n, k = input().split()
n = int(n)
k = int(k)
original_list = [0]*n
fenwick_list = [0]*n
for _ in range(k):
    query = (input().split())
    if(query[0]=='A'):
        set_value(int(query[1])-1, int(query[2]), original_list, fenwick_list)
    elif(query[0]=='Q'):
        print(interval_sum(int(query[1])-1, int(query[2])-1, fenwick_list))