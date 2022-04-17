# programming_notes

# 1. For bitwise operators
* To check odd or even : (n&1 == 0) ? EVEN : ODD
* A^A = 0 and A^0 = A<br>
   We can use it to check number which is not in pair
* To check if 2 numbers have opposite sign: ((a^b) < 0) ? OPPOSITE : NOT OPPOSITE
* To check if n is power of 2 => N && !(N&(N-1))

# 2. For LinkedList
* 3 pointers used <br>
  prev=NULL
  curr=head
  next=NULL
* 2 pointers / Slow and Fast pointers <br>
   slow = slow->next
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
   inorder(left)
   print(root)
   inorder(right)
   
  Preorder(root):<br>
   print(root)
   Preorder(left) 
   Preorder(right)
   
  Postorder(root):<br>
   Postorder(left)   
   Postorder(right)
   print(root)<br>
   
  LevelOrder(root):<br>
   Use Queue and add all the nodes level by level
* To Delete a tree use postorder traversal
* To Copy a tree use preorder traversal
* To create a tree from traversals one of the traversals should be inorder else tree could not be constructed

  
