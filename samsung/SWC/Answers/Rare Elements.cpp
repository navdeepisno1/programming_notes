//Author NAVDEEPISNO1
//Navdeep Sharma

//Question :

/*
Algorithm

*/

//Code

#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
    int level;
};

struct Point queue[1000];

int front = 0;
int back = 0;
int nFieldSize;
int nRareElements;

int field[100][100];
int rareElements[4][2];
int visited[100][100];

int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

void push(int x, int y, int level)
{
    queue[back].x = x;
    queue[back].y = y;
    queue[back].level = level;

    back++;
}

struct Point pop()
{
    return queue[front++];
}

bool empty()
{
    return front == back;
}

void initializeQueue()
{
    front = 0;
    back = 0;
}

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

bool isValid(int row, int col)
{
    if (row >= 0 && row < nFieldSize && col >= 0 && col < nFieldSize)
    {
        return true;
    }

    return false;
}

int bfs(int xSource, int ySource, int xDestination, int yDestination)
{
    //Push node to queue
    push(xSource, ySource, 0);
    visited[xSource][ySource] = 1;

    while (!empty())
    {
        struct Point tempPoint = pop();
        int tempX = tempPoint.x;
        int tempY = tempPoint.y;
        int tempLevel = tempPoint.level;

        if (tempX == xDestination && tempY == yDestination)
            return tempLevel;

        for (int i = 0; i < 4; i++)
        {
            int x = tempX + dirX[i];
            int y = tempY + dirY[i];

            if (isValid(x, y))
            {
                if (field[x][y] == 1)
                {
                    if (visited[x][y] == 0)
                    {
                        push(x, y, tempLevel + 1);
                        visited[x][y] = 1;
                    }
                }
            }
        }
    }

    return -1;
}

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

int solve()
{
    int res = 1000;

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
    int t;
    cin >> t;

    while (t--)
    {
        cin >> nFieldSize;

        cin >> nRareElements;

        for (int i = 0; i < nRareElements; i++)
        {
            int x, y;
            cin >> x >> y;

            rareElements[nRareElements][0] = x;
            rareElements[nRareElements][1] = y;
        }

        for (int i = 0; i < nFieldSize; i++)
        {
            for (int j = 0; j < nFieldSize; j++)
            {
                cin >> field[i][j];
            }
        }

        cout << solve() << endl;
    }

    return 0;
}