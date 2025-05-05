
import sys
def dfs(pigs, keys, key):
    if(pigs[key]==0):
        pigs[key]=1
        return dfs(pigs, keys, keys[key])
    else:
        return 0
def main():
    n = int(input())
    counter = 0
    keys = [0]
    for i in range(n):
        keys.append(int(input()))
    pigs = [0]*(n+1)
    if n==1:
        print(1)
    for i in range(1, n+1):
        if pigs[i] == 0:
            counter += 1
            pigs[i] = -1
            dfs(pigs, keys, keys[i])
        else:
            continue
    print(counter)
if __name__ == '__main__':
    main()
