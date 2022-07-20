//Author NAVDEEPISNO1
//Navdeep Sharma

//Question :

/*
Algorithm

Basic : We will use backtracking to enumerate all paths and return the path and score with maximum Score

*/

//Code

#include <iostream>

int mazeSize;
int maxScore;

int maze[100][100];
int resMaze[100][100];
int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {-1, 1, 0, 0};

using namespace std;

bool isSafe(int row, int col)
{
    if (row >= 0 && row < mazeSize && col >= 0 && col < mazeSize && (maze[row][col] == 0 || maze[row][col] == 2))
    {
        return true;
    }

    return false;
}

void updateResMaze()
{
    for (int i = 0; i < mazeSize; i++)
    {
        for (int j = 0; j < mazeSize; j++)
        {
            resMaze[i][j] = maze[i][j];
        }
    }
}

void solve(int row, int col, int score)
{
    if (row == mazeSize - 1 && col == mazeSize - 1)
    {
        if (score > maxScore)
        {
            maxScore = score;
            updateResMaze();
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int tempRow = row + dirX[i];
        int tempCol = col + dirX[i];

        if (isSafe(tempRow, tempCol))
        {
            int tempScore = (maze[tempRow][tempCol] == 2) ? 1 : 0;
            maze[tempRow][tempCol] = 3;
            solve(tempRow, tempCol, score + tempScore);
            maze[tempRow][tempCol] = (tempScore == 1) ? 2 : 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> mazeSize;

        for (int i = 0; i < mazeSize; i++)
        {
            for (int j = 0; j < mazeSize; j++)
            {
                cin >> maze[i][j];
            }
        }

        solve(0, 0, 0);
    }

    return 0;
}