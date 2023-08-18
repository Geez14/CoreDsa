class Node:
    def __init__(self, data):
       self.data = data
       self.next = None

class linklist:
    def __init__(self) -> None:
        self.head = None

if __name__ == "__main__":

    linklist.head = Node(23)
    secondNode = Node(232)
    thirdNode = Node(22321)
    print(thirdNode.data)


    linklist.head.next = secondNode
    # print(linklist.head.next) # TO debug the value fo second Node by line 17

    secondNode.next = thirdNode

    while(linklist.head!= None):
        print(linklist.head.data,end=" ")
        linklist.head = linklist.head.next
    print(linklist.head)