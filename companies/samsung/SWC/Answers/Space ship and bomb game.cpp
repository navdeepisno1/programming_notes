//Author NAVDEEPISNO1
//Navdeep Sharma

//Question : Space ship and bomb game.cpp

/*
Algorithm

Basic: At every level we will try to do all the function i.e move left,move right,or not move and using the bomb then return the maximum score

Step:
1 -> As given in question we will start from 
*/

//Code

//Include the necessary header files
#include <iostream>

//Namespace to avoid variable name confusion
using namespace std;

//Global variables
int size;

//Global BattleField
int battleField[100][100];

//Utility Functions

//Utility function to check if we could move to row and column
bool isSafe(int row, int col)
{
    if (row >= 0 && row < size && col >= 0 && col < 5)
    {
        return true;
    }

    return false;
}

//Utility function to get maximum score
int solve(int row, int col, int power, int effect)
{
    //Base condition when we get out of bound
    if (row < 0)
    {
        return 0;
    }

    int maxScore = 0;
    int score = 0;

    //move left,right and no where
    for (int i = -1; i <= 1; i++)
    {
        int nextRow = row - 1;
        int nextCol = col + i;

        //Only move if it safe to move
        if (isSafe(nextRow, nextCol))
        {
            //If we have an enemy
            if (battleField[nextRow][nextCol] == 2)
            {
                //If we have used up the power and we are in effect of the bomb
                if (power == 0 && effect > 0)
                {
                    score = solve(nextRow, nextCol, power, effect - 1);
                }
                //If we have power left i.e we could use bomb
                else if (power == 1)
                {
                    score = solve(nextRow, nextCol, power - 1, 5);
                }
            }
            else
            {
                if (power == 0 && effect > 0)
                {
                    score = solve(nextRow, nextCol, power, effect - 1);
                }
                else
                {
                    score = solve(nextRow, nextCol, power, 5);
                }
            }
        }

        if (score > maxScore)
        {
            maxScore = score;
        }
    }

    if (battleField[row][col] == 1)
        maxScore++;

    return maxScore;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> battleField[i][j];
            }
        }
    }

    return 0;
}