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


//que is FIFO : First In First Out

#include <iostream>
using namespace std;

int n,m,x,y,l;
int front=0;
int back=0;
int ans;

int A[1000][1000];
bool visited[1000][1000];
int UP[] = {1,2,4,7};
int DOWN[] = {1,2,5,6};
int LEFT[] = {1,3,6,7};
int RIGHT[] = {1,3,4,5};

struct node
{
	int x;
	int y;
	int l;
};

node que[1000000];

bool empty()
{
	return front==back;
}

void push(int x,int y,int l)
{	
	//add element to back
	que[back].x = x;
	que[back].y = y;
	que[back].l = l;

	//INcrease back pointer
	back++;
}

node pop()
{
	return que[front++];
}

void initializeQ()
{
	front = 0;
	back = 0;
}

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

bool isSafe(int r,int c)
{
	if(r<0 || c<0) return false;
	if(r>=n || c>=m) return false;
	if(visited[r][c]==true) return false;
	return true;
}

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

void solve()
{
	//check for 0;
	if(A[x][y]==0) return;
	
	ans = 1;

	//We will do BFS
	visited[x][y] = true;
	push(x,y,1);

	while(!empty())
	{
		//get front node && pop it
		node n = pop();
		int rT = n.x;
		int cT = n.y;
		int lT = n.l;

		//From here we will go to different directions 
		//Up Down Left Right
		//Based on the pipe present and each time we could go to certain directions 
		//Add 1 to answer each other		

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

int main() {
	int t;
	cin>>t;	
	
	while(t--)
	{
		cin>>n>>m>>x>>y>>l;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>A[i][j];
			}
		}

		initializeQ();
		setVisited();

		ans = 0;
		solve();
		cout<<ans<<endl;
	}
  
  return 0;
}
