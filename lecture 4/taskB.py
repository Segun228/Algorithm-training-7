import sys


def main():
    queue = []
    def push(n, queue):
        queue.append(n)
        print("ok")

    def pop(queue):
        if(len(queue)<1):
            print("error")
            return
        buf = queue[0]
        queue.pop(0)
        print(buf)

    def front(queue):
        if(len(queue)<1):
            print("error")
            return
        print(queue[0])

    def size(queue):
        print(len(queue))

    def clear(queue):
        queue.clear()
        print("ok")

    def exito():
        print("bye")


    while(True):
        buffer = input()
        command = list(buffer.split())
        if(len(command)==1):
            if(command[0]=="size"):
                size(queue)
            elif(command[0]=="exit"):
                exito()
                break
            elif(command[0]=="clear"):
                clear(queue)
            elif(command[0]=="front"):
                front(queue)
            elif(command[0]=="pop"):
                pop(queue)
        else:
            n = int(command[1])
            push(n, queue)
    pass


if __name__ == '__main__':
    main()