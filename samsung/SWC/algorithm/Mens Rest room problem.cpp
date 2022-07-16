//Author: navdeepisno1
//Navdeep Sharma

/*
Algorithm

Basic approach : We will calculate the longest path of continuos empty urinals and occupy the middle position in the path 
0=> Unoccupied
1=> Occupied

Steps:
1 -> Iterate for every men to occupy urinal
2 -> Create three variables to track maximum continuos path length , current continuos path length, and postion where continuos path
3 -> Iterate for every urinal postion and track maximum and 

*/

//Code

#include <iostream>

using namespace std;

void solve(int urinalSlots[], int nUrinals, int nMens)
{
    for (int men = 0; men < nMens; men++)
    {
        int maxContinuosEmptyUrinals = 0;
        int currentContinuosEmptyUrinals = 0;
        int lastPosmaxContinuosEmptyUrinals = 0;

        for (int pos = 0; pos < nUrinals; pos++)
        {
            if (urinalSlots[pos] == 0)
            {
                currentContinuosEmptyUrinals++;
            }
            if (urinalSlots[pos] == 1)
            {
                currentContinuosEmptyUrinals = 0;
            }
            if (currentContinuosEmptyUrinals >= maxContinuosEmptyUrinals)
            {
                maxContinuosEmptyUrinals = currentContinuosEmptyUrinals;
                lastPosmaxContinuosEmptyUrinals = pos;
            }
        }

        int startPosInTheLongestContinuosPath = lastPosmaxContinuosEmptyUrinals - maxContinuosEmptyUrinals + 1;
        int midPosInTheLongestContinuosPath = (startPosInTheLongestContinuosPath + lastPosmaxContinuosEmptyUrinals) / 2;
        urinalSlots[midPosInTheLongestContinuosPath] = 1;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int nUrinals;
        cin >> nUrinals;

        int nMens;
        cin >> nMens;

        int urinalSlots[nUrinals];

        for (int i = 0; i < nUrinals; i++)
        {
            urinalSlots[i] = 0;
        }

        solve(urinalSlots, nUrinals, nMens);
    }
}