import sys


def main():
    stack = []
    def push(n, stack):
        stack.append(n)
        print("ok")

    def pop(stack):
        if(len(stack)<1):
            print("error")
            return
        buf = stack[len(stack)-1]
        stack.pop(len(stack)-1)
        print(buf)

    def back(stack):
        if(len(stack)<1):
            print("error")
            return
        print(stack[len(stack)-1])

    def size(stack):
        print(len(stack))

    def clear(stack):
        stack.clear()
        print("ok")

    def exito():
        print("bye")


    while(True):
        buffer = input()
        command = list(buffer.split())
        if(len(command)==1):
            if(command[0]=="size"):
                size(stack)
            elif(command[0]=="exit"):
                exito()
                break
            elif(command[0]=="clear"):
                clear(stack)
            elif(command[0]=="back"):
                back(stack)
            elif(command[0]=="pop"):
                pop(stack)
        else:
            n = int(command[1])
            push(n, stack)
    pass


if __name__ == '__main__':
    main()