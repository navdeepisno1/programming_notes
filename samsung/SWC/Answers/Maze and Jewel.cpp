//Author NAVDEEPISNO1
//Navdeep Sharma

//Question : Maze and Jewel

/*
Algorithm

Basic : We will use backtracking to enumerate all paths and return the path and score with maximum Score

Steps:
1 -> We will start from starting of the maze i.e 0,0 and from there move in all the directions i.e UP,DOWN,LEFT,RIGHT
2 -> While moving we will check if we could move there or not .
3 -> We will mark the position as Visited and then move ahead with new answer
4 -> Then we will return and try another path. At every greater answer we will update the res and output maze path
*/

//Code

//Include Header files
#include <iostream>

//Namespace to avoid variable name confusion
using namespace std;

//Global variables
int mazeSize;
int maxScore;

//Global Arrays
int maze[100][100];
int resMaze[100][100];

//Utility arrays to move UP,LEFT,DOWN,RIGHT
int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {-1, 1, 0, 0};

//Utility Functions

//To check if we can move to row and column
bool isSafe(int row, int col)
{
    if (row >= 0 && row < mazeSize && col >= 0 && col < mazeSize && (maze[row][col] == 0 || maze[row][col] == 2))
    {
        return true;
    }

    return false;
}

//Helper Function to Update the result array
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

//Solution Utility function
void solve(int row, int col, int score)
{
    //Base condition i.e. We reach at the bottom right corner of Maze
    if (row == mazeSize - 1 && col == mazeSize - 1)
    {
        //If current Score is greater than Maximum Score update the results
        if (score > maxScore)
        {
            maxScore = score;
            updateResMaze();
        }
    }

    //Now we will move in all four direction i.e LEFT,RIGHT,UP,BOTTOM with the help of Utility Array
    for (int i = 0; i < 4; i++)
    {
        //New Rows and Columns
        int tempRow = row + dirX[i];
        int tempCol = col + dirX[i];

        //Only move if it is safer to move
        if (isSafe(tempRow, tempCol))
        {
            //Get the score if it is jewel score is 1 else 0
            int tempScore = (maze[tempRow][tempCol] == 2) ? 1 : 0;

            //Mark as visited
            maze[tempRow][tempCol] = 3;

            //Move with new row and column and score
            solve(tempRow, tempCol, score + tempScore);

            //Unmark the visited array
            maze[tempRow][tempCol] = (tempScore == 1) ? 2 : 0;
        }
    }
}

//Utility function to print the maximum score and the path which is used to achieve that score
void printSolution()
{
    cout << maxScore << endl;

    for (int i = 0; i < mazeSize; i++)
    {
        for (int j = 0; j < mazeSize; j++)
        {
            cout << resMaze[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

//Main function
int main()
{
    //Get test cases
    int t;
    cin >> t;

    //Run loop while t!=0 (0 = false)
    while (t--)
    {
        //Get size of maze
        cin >> mazeSize;

        //Get maze values
        for (int i = 0; i < mazeSize; i++)
        {
            for (int j = 0; j < mazeSize; j++)
            {
                cin >> maze[i][j];
            }
        }

        //Get the maximum score and its path starting from 0,0
        solve(0, 0, 0);
        printSolution();
    }

    //Yeah the program executed successfully
    return 0;
}