# programming_notes

# 1. For bitwise operators

* To check odd or even : (n&1 == 0) ? EVEN : ODD
* A^A = 0 and A^0 = A<br>
   We can use it to check number which is not in pair
* To check if 2 numbers have opposite sign: ((a^b) < 0) ? OPPOSITE : NOT OPPOSITE
* To check if n is power of 2 => N && !(N&(N-1))

# 2. For LinkedList

* 3 pointers used 
  prev=NULL
  curr=head
  next=NULL
* 2 pointers / Slow and Fast pointers 
  slow = slow->next
  fast = fast->next->next

# 3. For Trees

* Height = 1 + max(left,right)  and height of empty tree = -1;
*
