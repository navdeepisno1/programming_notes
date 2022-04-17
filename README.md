# programming_notes

# 1. For bitwise operators
* To check odd or even : (n&1 == 0) ? EVEN : ODD
* A^A = 0 and A^0 = A<br>
   We can use it to check number which is not in pair
* To check if 2 numbers have opposite sign: ((a^b) < 0) ? OPPOSITE : NOT OPPOSITE
* To check if n is power of 2 => N && !(N&(N-1))

# 2. For LinkedList
* 3 pointers used <br>
  prev=NULL<br>
  curr=head<br>
  next=NULL
* 2 pointers / Slow and Fast pointers <br>
  slow = slow->next<br>
  fast = fast->next->next
* Cycle detection 
  if(slow==fast) <br>
   true <br>
  else <br>
   false

# 3. For Trees
* Height = 1 + max(left,right)  and height of empty tree = -1;
* For a tree to be bst every node must fulfill the condition including the parents of parents and upto root
* Traversals <br>
  Inorder(root): <br>
   inorder(left)<br>
   print(root)<br>
   inorder(right)<br>
   
  Preorder(root):<br>
   print(root)<br>
   Preorder(left) <br>  
   Preorder(right)<br>
   
  Postorder(root):<br>
   Postorder(left)   <br>
   Postorder(right)<br>
   print(root)<br>
   
  LevelOrder(root):<br>
   Use Queue and add all the nodes level by level
