//Author NAVDEEPISNO1
//Navdeep Sharma

//Question :

/*
Algorithm

*/

//Code

#include <iostream>

int size;
int room[100][100];
int blindSpots[100][100];

using namespace std;

int isValid(int row, int col)
{
    if (row >= 0 && row < size && col >= 0 && col < size && room[row][col] == 0)
    {
        return true;
    }
    return false;
}

int getBlindSpots(int row,int col)
{
    int res = 0;
    
    //UP
    for(int i=row;i>0;i--)
    {
        if(room[i][j]==1)
    }
}

void setBlindSpots()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (room[i][j] == 0)
            {
                blindSpots[i][j] = getBlindSpots(i,j);
            }
            else
            {

            }
        }
    }
}

void print()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << room << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> room[i][j];
            }
        }

        setBlindSpots();

        print();
    }

    return 0;
}