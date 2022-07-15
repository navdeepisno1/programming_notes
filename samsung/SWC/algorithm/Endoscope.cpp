//Author NAVDEEPISNO1
//Navdeep Sharma



/*
ALgorithm

1 We will check for current position if it is zero return 0 as answer
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


//que is FIFO : First In First Out

#include <iostream>
using namespace std;

//All global variables
int n,m,x,y,l;
int front=0;
int back=0;
int ans;

//All global arrays
int A[1000][1000];
bool visited[1000][1000];
int UP[] = {1,2,4,7};
int DOWN[] = {1,2,5,6};
int LEFT[] = {1,3,6,7};
int RIGHT[] = {1,3,4,5};

//Node structure for Queue
struct node
{
	int x;
	int y;
	int l;
};

//Our Queue 
//Never use queue as variable name it will give error
node que[1000000];

//To check if our queue is empty
bool empty()
{
	return front==back;
}

//Push the data to queue
void push(int x,int y,int l)
{	
	//As we are not using pointers so we dont require to create variable using malloc
	
	//add element to back
	que[back].x = x;
	que[back].y = y;
	que[back].l = l;

	//Increase back pointer
	back++;
}

//Pop the data 
//We are using same function to get front data and pop it 
node pop()
{
	return que[front++];
}

//For every testcase empty the queue by reinitialising the queue
void initializeQ()
{
	front = 0;
	back = 0;
}

//For every test case we need to set visited array false
void setVisited()
{
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			visited[i][j] = false;
		}
	}
}

//Check boundary conditions and visited 
bool isSafe(int r,int c)
{
	if(r<0 || c<0) return false;
	if(r>=n || c>=m) return false;
	if(visited[r][c]==true) return false;
	return true;
}

//Self Defined
bool canGoUp(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		if(A[x][y]==UP[i])
		{
			return true;
		}
	}

	return false;
}

//Self Defined
bool canGoDown(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		if(A[x][y]==DOWN[i])
		{
			return true;
		}
	}

	return false;
}

//Self Defined
bool canGoLeft(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		if(A[x][y]==LEFT[i])
		{
			return true;
		}
	}

	return false;
}

//Self Defined
bool canGoRight(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		if(A[x][y]==RIGHT[i])
		{
			return true;
		}
	}

	return false;
}

//Helper function to solve every test case individually
void solve()
{
	//check for 0;
	if(A[x][y]==0) return;
	
	//As the endoscope can move in the current pipe initialise the answer with 1;
	ans = 1;

	//We will do BFS with queue
	
	//Mark starting postion as marked and push it to queue
	visited[x][y] = true;
	push(x,y,1);

	//Run while queue is not empty
	while(!empty())
	{
		//get front node && pop it
		node n = pop();
		int rT = n.x;
		int cT = n.y;
		int lT = n.l;

		//From here we will go to different directions 
		//Up Down Left Right		
		//Add 1 to answer each other		
		
		//We have to check both the current pipe and the next pipe to ensure smooth travel

		//Up
		if(isSafe(rT-1,cT) && lT+1<=l)
		{
			if(canGoDown(rT-1,cT))
			{
				if(canGoUp(rT,cT))
				{
					visited[rT-1][cT] = true;
					push(rT-1,cT,lT+1);
					ans++;
				}
			}
		}

		//Down
		if(isSafe(rT+1,cT) && lT+1<=l)
		{
			if(canGoUp(rT+1,cT))
			{
				if(canGoDown(rT,cT))
				{
					visited[rT+1][cT] = true;
					push(rT+1,cT,lT+1);
					ans++;
				}
			}
		}

		//Left
		if(isSafe(rT,cT-1) && lT+1<=l)
		{
			if(canGoRight(rT,cT-1))
			{
				if(canGoLeft(rT,cT))
				{
					visited[rT][cT-1] = true;
					push(rT,cT-1,lT+1);
					ans++;
				}
			}
		}

		//Right
		if(isSafe(rT,cT+1) && lT+1<=l)
		{
			if(canGoLeft(rT,cT+1))
			{
				if(canGoRight(rT,cT))
				{
					visited[rT][cT+1] = true;
					push(rT,cT+1,lT+1);
					ans++;
				}
			}
		}
	}

}

//Main function
int main() {
	
	//Get the number of testcases
	int t;
	cin>>t;	
	
	//While t!=0 because 0==false
	while(t--)
	{
		//Get matrix size
		//Get current location or starting location
		//Get maximum length of endoscope
		cin>>n>>m>>x>>y>>l;

		//Fill matrix with data
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>A[i][j];
			}
		}
		
		//Reset the queue and visited array
		initializeQ();
		setVisited();

		//Set answer according to quetion as 0 or -1
		ans = 0;
		
		//Call helper function
		solve();
		
		//Output the result in each line
		cout<<ans<<endl;
	}
	
  return 0;
}
