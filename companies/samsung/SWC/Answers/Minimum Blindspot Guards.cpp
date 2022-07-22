//Author NAVDEEPISNO1
//Navdeep Sharma

//Question :

/*
Algorithm

*/

//Code

#include <iostream>

int size;
int room[5][5];
int answer = 10000;

using namespace std;

struct Position
{
    int row;
    int col;
};

Position guards[3];

int isValid(int row, int col)
{
    if (row >= 0 && row < size && col >= 0 && col < size && room[row][col] == 0)
    {
        return true;
    }
    return false;
}

int getBlindSpotForPosition(int row, int col)
{
    int res = 0;

    int i, j;

    //Right
    j = col + 1;
    while (j < size)
    {
        if (room[row][j] == 0)
        {
            j++;
        }
        else
        {
            while (j < size && room[row][j] == 1)
            {
                j++;
            }
            if (j < size - 1)
            {
                res++;
            }
        }
    }

    //Left
    j = col - 1;
    while (j >= 0)
    {
        if (room[row][j] == 0)
        {
            j--;
        }
        else
        {
            while (j >= 0 && room[row][j] == 1)
            {
                j--;
            }
            if (j >= 1)
            {
                res++;
            }
        }
    }

    //bottom
    i = row + 1;
    while (i < size)
    {
        if (room[i][col] == 0)
        {
            i++;
        }
        else
        {
            while (i < size && room[i][col] == 1)
            {
                i++;
            }
            if (i < size - 1)
            {
                res++;
            }
        }
    }

    //UP
    i = row - 1;
    while (i >= 0)
    {
        if (room[i][col] == 0)
        {
            i--;
        }
        else
        {
            while (i >= 0 && room[i][col] == 1)
            {
                i--;
            }
            if (i >= 1)
            {
                res++;
            }
        }
    }

    return res;
}

void findBlindSpots()
{
    int blindSpots = 0;
    for (int i = 0; i < 3; i++)
    {
        blindSpots += getBlindSpotForPosition(guards[i].row, guards[i].col);
    }

    answer = (blindSpots < answer) ? blindSpots : answer;
}

void placeGuard3()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (room[i][j] != 1)
            {
                room[i][j] = 1;
                guards[2].row = i;
                guards[2].col = j;
                findBlindSpots();
                room[i][j] = 0;
            }
        }
    }
}

void placeGuard2()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (room[i][j] != 1)
            {
                room[i][j] = 1;
                guards[1].row = i;
                guards[1].col = j;
                placeGuard3();
                room[i][j] = 0;
            }
        }
    }
}

void placeGuard1()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (room[i][j] != 1)
            {
                room[i][j] = 1;
                guards[0].row = i;
                guards[0].col = j;
                placeGuard2();
                room[i][j] = 0;
            }
        }
    }
}

void solve()
{
    placeGuard1();
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
            for (int j = 0; j < size; j++)
            {
                cin >> room[i][j];
            }
        }

        solve();

        cout << answer << endl;
    }

    return 0;
}