import sys
def finder(x, parents):
    if(parents[x] != x):
        parents[x] = finder(parents[x], parents)
    return parents[x]

def check_connection(x, y, parents, lev):
    par_from_y = finder(y, parents)
    par_from_x = finder(x, parents)
    if (par_from_x != par_from_y):
        if (lev[par_from_x] < lev[par_from_y]):
            parents[par_from_x] = par_from_y
        elif (lev[par_from_x] > lev[par_from_y]):
            parents[par_from_y] = par_from_x
        else:
            parents[par_from_y] = par_from_x
            lev[par_from_x] += 1
        return True
    return False

def main():
    n, k= map(int, input().split())
    components = n
    parents = [i for i in range(n)]
    lev = [0]* n
    for i in range(k):
        x, y = map(int, input().split())
        x-= 1
        y-= 1
        if(check_connection(x, y, parents, lev)):
            components-= 1
        if(components==1):
            print(i + 1)
            break
if __name__ == "__main__":
    main()