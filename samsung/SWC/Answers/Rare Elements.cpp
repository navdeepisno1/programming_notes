//Author NAVDEEPISNO1
//Navdeep Sharma

//Question :

/*
Algorithm

Basic Approach: Find all max distance from all rare elements to path and get minimum of that

Steps:
1 -> Input necessary variables like fieldSize, number of rare elements, and Field array (0: no Path || 1 : Path)
2 -> We will use a BFS approach so we will create a queue and its requires functions i.e push ,pop ,empty
3 -> We will iterate over every coordinate in the field and try to get maximum distace from every rare element
4 -> Out of every maximum distance we will get the minimum distance and print the output

*/

//Code

//Include necessary header files
#include <iostream>

//Namespace to avoid naming confusion
using namespace std;

//Structure to hold coordinates/location of points and their distance
struct Point
{
    int x;
    int y;
    int distance;
};

//Create the queue to be used in BFS
struct Point queue[1000];

//Tracking variables for Queue
int front = 0;
int back = 0;

//helper function to push elements to queue
void push(int x, int y, int distance)
{
    queue[back].x = x;
    queue[back].y = y;
    queue[back].distance = distance;

    back++;
}

//helper function to pop as well as get front element in queue
struct Point pop()
{
    return queue[front++];
}

//helper to check if queue is empty or not
bool empty()
{
    return front == back;
}

//Field Size and Number of RareElements
int nFieldSize;
int nRareElements;

//Field Matrix, Rare Elements Array, And Visited Array
int field[100][100];
int rareElements[4][2];
int visited[100][100];

//Utility array to move in four direction Left,Right,Up and Down to avoid hard coding
int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

//For initializing or reseting queue
void initializeQueue()
{
    front = 0;
    back = 0;
}

//For initializing or reseting visited array
//0 = Unvisited || 1 = Visited
void initializeVisited()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            visited[i][j] = 0;
        }
    }
}

//Check if we could access the row and col
bool isValid(int row, int col)
{
    if (row >= 0 && row < nFieldSize && col >= 0 && col < nFieldSize)
    {
        return true;
    }

    return false;
}

//Utility function to Run BFS
int bfs(int xSource, int ySource, int xDestination, int yDestination)
{
    //Push node to queue
    push(xSource, ySource, 0);

    //Mark it as Visited
    visited[xSource][ySource] = 1;

    //We will run the loop until the queue is empty
    while (!empty())
    {
        //Get the front element and pop it
        struct Point tempPoint = pop();
        int tempX = tempPoint.x;
        int tempY = tempPoint.y;
        int tempDistance = tempPoint.distance;

        //If we reach the Destination return the Distance
        if (tempX == xDestination && tempY == yDestination)
            return tempDistance;

        //Now We will move from current location to UP ,DOWN,LEFT and BOTTOM using directional arrays
        for (int i = 0; i < 4; i++)
        {
            int x = tempX + dirX[i];
            int y = tempY + dirY[i];

            //We will check if we can move or access the new x and y
            if (isValid(x, y))
            {
                //We could only move if there is path in field
                if (field[x][y] == 1)
                {
                    //We could only move if the path is not visited
                    if (visited[x][y] == 0)
                    {
                        //Push the new path to queue and increasing the distance
                        push(x, y, tempDistance + 1);

                        //Mark the new path as visited
                        visited[x][y] = 1;
                    }
                }
            }
        }
    }

    return -1;
}

//Utility function to get distance maximum from RareElements
int getMaximumDistanceFromRareElements(int row, int col)
{
    int res = 0;

    if (field[row][col] == 1)
    {
        for (int i = 0; i < nRareElements; i++)
        {
            initializeQueue();
            initializeVisited();

            int tempRes = bfs(row, col, rareElements[i][0], rareElements[i][1]);

            res = max(res, tempRes);
        }
    }

    return res;
}

//Main Helper function to solve the program or get minimum distance among all the maximum distacnes
int solve()
{
    int res = 1000;

    //For every coordinate get maximum distance and from them get minimum of all
    for (int i = 0; i < nFieldSize; i++)
    {
        for (int j = 0; j < nFieldSize; j++)
        {
            int tempRes = getMaximumDistanceFromRareElements(i, j);

            res = min(res, tempRes);
        }
    }

    return res;
}

int main()
{
    //Get the number of testcases
    int t;
    cin >> t;

    //iterate while t!=0 (o = false)
    while (t--)
    {
        //Get field size
        cin >> nFieldSize;

        //Get number of rare elements
        cin >> nRareElements;

        //Get rare elements location
        for (int i = 0; i < nRareElements; i++)
        {
            int x, y;
            cin >> x >> y;

            rareElements[i][0] = x;
            rareElements[i][1] = y;
        }

        //Get the field (0 = No path || 1 = Path)
        for (int i = 0; i < nFieldSize; i++)
        {
            for (int j = 0; j < nFieldSize; j++)
            {
                cin >> field[i][j];
            }
        }

        //Output the result
        cout << solve() << endl;
    }

    return 0;
}