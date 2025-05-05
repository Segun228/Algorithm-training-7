from queue import Queue
import sys
def main():
    n = int(input())
    values = list(map(int, input().split()))
    rounds = [0] * n
    left_neigbor = [(i - 1 + n) % n for i in range(n)]
    right_neighbor = [(i + 1) % n for i in range(n)]
    q = Queue()
    for i in range(n):
        if(values[left_neigbor[i]] > values[i] and values[right_neighbor[i]] > values[i]):
            q.put(i)
    round_nom = 0
    while(not q.empty() and n > 2):
        round_nom += 1
        size = q.qsize()
        for j in range(size):
            idx = q.get()
            if(rounds[idx]!=0):
                continue
            rounds[idx] = round_nom
            leftNominant = left_neigbor[idx]
            rightNominant = right_neighbor[idx]
            right_neighbor[leftNominant] = rightNominant
            left_neigbor[rightNominant] = leftNominant
            n -= 1
            if(values[left_neigbor[leftNominant]] > values[leftNominant] and values[right_neighbor[leftNominant]] > values[leftNominant] and rounds[leftNominant] == 0):
                q.put(leftNominant)
            if(values[left_neigbor[rightNominant]] > values[rightNominant] and values[right_neighbor[rightNominant]] > values[rightNominant] and rounds[rightNominant] == 0):
                q.put(rightNominant)
    print(' '.join(map(str, rounds)))


if __name__ == '__main__':
    main()
