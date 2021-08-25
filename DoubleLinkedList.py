class Node:
    def __init__(self,data,prev = None,next = None):
        self.data = data
        self.next = next
        self.prev = prev
class DoublyLinkedList:
    def __init__(self):
        self.head = None
    def InsertBeginning(self,data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
        else:
            self.head.prev = newNode
            newNode.next = self.head
            self.head = newNode
    def InsertEnd(self,data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            newNode.prev = temp
            temp.next = newNode
    def InsertAfter(self,data1,data):
        temp = self.head
        while temp is not None:
            if temp.data is data1:
                break
            temp = temp.next
        if temp is None:
            print("Not in List")
            return
        if temp is self.head:
            self.InsertBeginning(data)
            return
        else:
            newNode = Node(data)
            newNode.prev = temp
            newNode.next = temp.next
            (temp.next).prev = newNode
            temp.next = newNode
    def DeleteNode(self,data):
        temp = self.head
        while temp is not None:
            if temp.data is data:
                break
            temp = temp.next
        if temp is None:
            print("Not in List")
            return
        if temp is self.head:
            self.head = temp.next
            self.head.prev = None
            temp = None
        else:
            (temp.prev).next = temp.next
            (temp.next).prev = temp.prev
            temp = None
    def Display(self):
        temp = self.head
        print("Normal")
        while temp is not None:
            print(temp.data,end = " ")
            if temp.next is None:
                break
            temp = temp.next
        print("\nReversed")
        while temp is not None:
            print(temp.data,end =" ")
            temp = temp.prev
        print()
linkedlist = DoublyLinkedList()
linkedlist.InsertBeginning("N")
linkedlist.InsertBeginning("A")
linkedlist.InsertEnd("S")
linkedlist.InsertAfter("N","T")
#A N T S
linkedlist.Display()
linkedlist.DeleteNode("A")
#N T S
linkedlist.Display()
linkedlist.DeleteNode("T")
#N S
linkedlist.Display()

            
        