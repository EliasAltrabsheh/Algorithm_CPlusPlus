/* This program list will target looking at double linked lists.

each link contains a pointer to the previous link as well as to the next link.
(Don’t confuse this with a double-ended list, where the links are the same as a normal singly linked list but the list maintains a pointer to the end of the list.)

A potential problem with ordinary singly linked lists is that it’s difficult to traverse backward along the list.

In this hour, you learned the following:
● In a sorted linked list, the links are arranged in order of ascending (or sometimes descending) key value.
● Insertion in a sorted list takes O(N) time because the correct insertion point must be found. Deletion of the smallest link takes O(1) time.
● A sorted list is the basis for the list insertion sort.
● The list insertion sort is faster than the ordinary insertion sort, but requires twice as much memory space.
● In a doubly linked list, each link contains a pointer to the previous link as well as the next link.
● A doubly linked list permits backward traversal as well as deletion from the end of the list.

Q-When would I use a sorted list?

When you want quick access to the item with the smallest (or largest) key. This is what a priority queue does.
 The advantage of a sorted-list implementation over a sorted-array implementation is that you don’t need to move any items to insert a new one;
 just rearrange some pointers. That makes it more efficient, although harder to program.

Q When would I use the list insertion sort?
In specialized situations. If you’ve already created a sorted linked list, you’ve done most of the sort already.
To finish the sort, just copy the list into an array. This takes O(N) time, so it’s very fast.
QAre doubly linked lists important? A The list in many class libraries is a doubly linked list. This is true of the list class in the C++ STL.
 The doubly linked list is far more versatile than a singly linked list, and only slightly less efficient.
 
