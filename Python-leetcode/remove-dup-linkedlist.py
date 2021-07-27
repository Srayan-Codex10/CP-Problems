class ListNode():
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def removeDuplicates(head:ListNode) -> ListNode:
    temp = head
    iter_list = ListNode()
    iter_list = head
    while(iter_list.next is not None):
        iter_list = iter_list.next
        if(temp.val == iter_list.val):
            temp.next = iter_list.next
        else:
            temp = iter_list
    return head

head = ListNode(int(input("Head: ")))
temp = head
size =int(input('Size: '))
for i in range(size):
    node = ListNode(int(input()))
    temp.next = node
    temp = node
filtered_list = removeDuplicates(head)
while(filtered_list is not None):
    print(str(filtered_list.val) + '->',end=' ')
    filtered_list = filtered_list.next
