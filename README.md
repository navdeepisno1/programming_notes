# programming_notes

# 1. For bitwise operators
* To check odd or even : (n&1 == 0) ? EVEN : ODD
* A^A = 0 and A^0 = A<br>
   We can use it to check number which is not in pair
* To check if 2 numbers have opposite sign: ((a^b) < 0) ? OPPOSITE : NOT OPPOSITE
* To check if n is power of 2 => N && !(N&(N-1))

# 2. For LinkedList
* 3 pointers used <br>
  prev=NULL <br>
  curr=head <br>
  next=NULL
* 2 pointers / Slow and Fast pointers <br>
   slow = slow->next <br>
   fast = fast->next->next
* Cycle detection <br> 
  if(slow==fast) 
   true 
  else 
   false

# 3. For Trees
* Height = 1 + max(left,right)  and height of empty tree = -1;
* For a tree to be bst every node must fulfill the condition including the parents of parents and upto root
* Traversals <br>
  Inorder(root): <br>
   inorder(left) <br>
   print(root) <br>
   inorder(right) <br>
   
  Preorder(root):<br>
   print(root) <Br>
   Preorder(left) <br>
   Preorder(right) <br>
   
  Postorder(root):<br>
   Postorder(left)   <br>
   Postorder(right) <br>
   print(root)<br>
   
  LevelOrder(root):<br>
   Use Queue and add all the nodes level by level followed by pop
* To Delete a tree use postorder traversal
* To Copy a tree use preorder traversal
* To create a tree from traversals one of the traversals should be inorder else tree could not be constructed
* Left view is first element of every level in LevelOrder Traversal 
* Right view is last element of every level in LevelOrder Traversal 
* Horizontal distance:<br>
   root = zero
   for left node level-1
   for right node level+1
   
   
# 4. For Matrix
* To rotate a matrix Anti Clockwise - Reverse every row and then perform Transpose
* To rotate a matrix Clockwise - Transpose and Reverse every row
* To sort a matrix create an Array of same size and sort it and place the elements in the matrix one by one;
* Transpose of matrix is swapping A[i][j] with A[j][i]

# 5. For Priority Queue
* Another method for making min-heap using default priority_queue:

This is frequently used in Competitive Programming. We first multiply all elements with (-1). Then we create a max heap (max heap is the default for priority queue). When we access the data and want to print it we simply multiply those elements with (-1) again.

# 6. STL and there internal Data structures and common methods

| STL Data Structure | Internal Implementation using |
| ---------------- | ---------------------------: |
| set                | BST                           |
| map                | Self Balancing Tree           |
| unordered_map      | HashTable                     |
| priority_queue     | arrays / vector                 |
| stack              | vector / deque / list             |
| queue              | vector / deque / list             |
| vector             | dynamic array and its pointer |
| graph             | 2D Array / LinkedList Array / Vector of Vector |

# 7. Some important Results about  Binary Tree and BSTs
* Inorder of BST is always in sorted order.
* If n is the number of nodes present in the tree. Then, 
* The total number of possible Binary search Trees = (2n!) / ((n+1)!*n!).
* The total numebr of possible Binary Trees = (total possible number of BSTs)*(n!). 

# 8. For balanced brackets
* We can use a stack to check if a string containing multiple type of brackets like [,{,( is balanced or not . <br>
  1 Start scanning in the string from left to right <br>
  2 If it is opening bracket or stack is empty push to stack else if top the character is matching opening bracket for the current closing bracket POP the element from the stack <br>
  3 Check if stack is empty or not. (EMPTY = Balanced) <br>
  
 * For string containing single type of brackets we can use 2 counters to check number of opening and closing brackets at particular time <br>
   1 Initialize both counters to zero <br>
   2 If at any point number of opening brackets is greater than half the length of string . Then it is unbalanced <br>
   3 If at any point number of closing brackets is greater than number of opening brackets .Then is is unbalanced <br>
   
