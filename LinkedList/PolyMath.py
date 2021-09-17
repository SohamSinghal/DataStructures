class Node:
  def __init__(self,coeff = 0,pow = 0):
    self.coeff = coeff
    self.pow = pow
    self.next = None
class Polynomial:
  def __init__(self):
    self.head = None
  def Create(self,expression):
    for ele in expression:
      newNode = Node(ele[0],ele[1])
      if self.head is None:
        self.head = newNode
      else:
        temp = self.head
        while temp.next is not None:
          temp = temp.next
        temp.next = newNode
  def add(self,poly1,poly2):
    temp1 = poly1.head
    temp2 = poly2.head
    sum = []
    while temp1 != None and temp2 != None:
      if temp1.pow == temp2.pow:
        sum.append([temp1.coeff+temp2.coeff,temp2.pow])
        temp1 = temp1.next
        temp2 = temp2.next
      elif temp1.pow>temp2.pow:
        sum.append([temp1.coeff,temp1.pow])
        temp1 = temp1.next
      else:
        sum.append([temp2.coeff,temp2.pow])
        temp2 = temp2.next
    if temp1 is None and temp2 is not None:
      while temp2 is not None:
        sum.append([temp2.coeff,temp2.pow])
        temp2 = temp2.next
    elif temp1 is not None and temp2 is None:
      while temp1 is not None:
        sum.append([temp1.coeff,temp1.pow])
        temp1 = temp1.next
    self.Create(sum)
  def display(self):
    temp = self.head
    while temp.next is not None:
      if temp.next.coeff<0:
        print("{}x^{}".format(temp.coeff,temp.pow),end = "")
      else:
        print("{}x^{}".format(temp.coeff,temp.pow),end = "+")
      temp = temp.next
      if temp.next is None and temp.pow == 0:
        print(temp.coeff,"=0")
      elif temp.next is None:
        print("{}x^{}=0".format(temp.coeff,temp.pow))
poly1 = Polynomial()
poly2 = Polynomial()
poly1.Create([[1,2],[-2,1]]) #x^2 - 2x = 0 
poly2.Create([[4,3],[2,2],[-3,1]]) #4x^3+2x^2-3x = 0
poly1.display()
poly2.display()
poly = Polynomial()
poly.add(poly1,poly2)
poly.display()