import sys

def dfs(pig_number, keys, visited, in_path):
    if visited[pig_number]:
        return False
    if in_path[pig_number]:
        return True
    in_path[pig_number] = True
    res = dfs(keys[pig_number], keys, visited, in_path)
    in_path[pig_number] = False
    visited[pig_number] = True
    return res

def main():
    n = int(input())
    keys = []
    keys.append(0)
    keys.extend([int(input()) for i in range(n)])
    visited = [False] * (n + 1)
    in_path = [False] * (n + 1)
    counter = 0
    for i in range(1, n + 1):
        if(not visited[i]):
            if dfs(i, keys, visited, in_path):
                counter += 1
    print(counter)

if __name__ == '__main__':
    main()