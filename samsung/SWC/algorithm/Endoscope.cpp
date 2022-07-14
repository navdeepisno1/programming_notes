/*
ALgorithm

1 We will check for current position if it is zero return 0 as naswer
2 Now we will run a BFS from the current node and implement it using queue
3 Queue is created using array
4 Initialise the answer with 1
5 We will push the current node to queue
6 we will keep doing the same pop and push until the queue is empty.
7 we will move in all the directions 
8 Remember in order to move in a particular direction both the current and next pipe should be in the same direction and we must check that the pipe is not visited wither
9 Each time we Enter a pipe push it to the queue and mark it as visited in some visited matrix and increment the answer
10 At last return the answer when we dont have any more pipe to visit or the max length of enoscope is crossed 
11 Note: Check for boundary condtions and Visited array as well as that length must be less than equal to max length
12 Return the answer

*/
