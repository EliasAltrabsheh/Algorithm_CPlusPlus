/* Why might you want to use a tree?
 Usually because it combines the advantages of two other structures: an ordered array and a linked list.
 search a tree quickly, as you can an ordered array, and you can also insert and delete items quickly,
as you can with a linked list. Let’s explore these topics a bit before delving into the details of trees.

  A Tree Analogy in Your Computer:

encountered tree is the hierarchical file structure in a computer system.
The root directory of a given device (designated with the backslash, as in C:\, on many systems) is the tree’s root.

  Clearly a hierarchical file structure is not a binary tree because a directory can have many children. A complete pathname,
 such as C:\SALES\EAST\NOVEMBER\SMITH.DAT, corresponds to the path from the root to the SMITH.DAT leaf node. Terms used for file structures, such as root and path, were borrowed from tree theory.

 In this hour, you’ve learned the following:
● Trees consist of nodes (circles) connected by edges (lines).
● The root is the topmost node in a tree; it has no parent.
● In a binary tree, a node has at most two children.
● In a binary search tree, all the nodes that are left descendants of node A have key values less than A; all the nodes that are A’s right descendants have key values greater than (or equal to) A.
● Trees perform searches,insertions,and deletions in O(log N) time.
● Nodes represent the data-objects being stored in the tree.
● Edges are most commonly represented in a program by pointers to a node’s children (and sometimes to its parent).
● An unbalanced tree is one whose root has many more left descendents than right descendants, or vice versa.
● Searching for a node involves comparing the value to be found with the key value of a node, and going to that node’s left child if the key search value is less, or to the node’s right child if the search value is greater.
● Insertion involves finding the place to insert the new node, and then changing a child data member in its new parent to refer to it

Q Trees seems much more complicated than arrays orlinked lists. Are they really useful?

Trees are probably the single most useful data structure. They have comparatively fast searching,insertion,and deletion,which is not the case with simpler structures.
 For storing large amounts of data, a tree is usually the first thing you should consider.

Q Don’t you sometimes need to rearrange the nodes in a tree when you insert a new node?
 Never. The new node is always attached to a leaf node, or as the missing child of a node with one child. However, when deleting a node rearrangement may be necessary.

Q Can we use the tree we’ve seen in this hour as a general-purpose data storage structure?

A Only in some circumstances. As we’ll discuss in Hour 17, simple trees work poorly when the order of data insertion creates an unbalanced tree.

Traversing a tree means visiting each node in a specified order. This process is not as commonly used as finding, inserting, and deleting nodes.
One reason for this is that traversal is not particularly fast. But traversing a tree has some surprisingly useful applications and is theoretically interesting.
