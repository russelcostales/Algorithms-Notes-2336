# Given a linked list:
# ( A ) -> ( B ) -> ( C ) -> ( D ) -> ( E )

# N1:
# value = A
# prev = null
# next = memory address of ( B )

# N2:
# value = B
# prev = memory address of ( A ) 
# next = memory address of ( C )

# N2:
# prev = C
# value = memory address of ( A ) 
# next = memory address of ( C )

# Time complexities:
# insert head  -> o(1)
# delete head  -> o(1)
# get head     -> o(1)
# insert       -> o(n)
# delete       -> o(n)
# get          -> o(n)

class Node:
    def __init__(self, value, previous, next):
        self.value = value
        self.prev = previous
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None
    
    def delete(self, value):
        current_node = self.head
        
        if (self.head == None):
            return

        if (current_node.value == value):
            self.delete_first()
            return
        
        current_node = current_node.next

        while current_node != None:
            if (current_node.value == value):
                current_node.prev.next = current_node.next
                current_node.next.prev = current_node.prev
                return

            current_node = current_node.next

    def delete_first(self):
        if (self.head != None):
            self.head.prev = None
            self.head = self.head.next
            return
        
    def get(self, value):
        current_node = self.head

        while current_node != None:
            if (current_node.value == value):
                return current_node.value

            current_node = current_node.next
    
    def insert_first(self, value):
        new_node = Node(value, None, self.head)
        if self.head != None:
            self.head.prev = new_node
        self.head = new_node
        
myLinkedList = LinkedList()
myLinkedList.insert_first("John")       # -> John
myLinkedList.insert_first("Elizabeth")  # -> Elizabeth -> John
myLinkedList.insert_first("Mike")       # -> Mike  -> Elizabeth -> John
myLinkedList.insert_first("Bryan")      # -> Bryan -> Mike ->Elizabeth -> John

print(myLinkedList.get(""))             # -> None
print(myLinkedList.get("Bryan"))        # -> Brian
print(myLinkedList.get("Mike"))         # -> Mike

myLinkedList.delete("Mike")

print(myLinkedList.get("John"))         # -> John
print(myLinkedList.get("Elizabeth"))    # -> Elizabeth
print(myLinkedList.get("Mike"))         # --> None
print(myLinkedList.get("Bryan"))        # --> Bryan