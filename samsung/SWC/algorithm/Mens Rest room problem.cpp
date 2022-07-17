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
3 -> Iterate for every urinal postion and track maximum length continuos unoccupied urinals and and the location where it ends
4 -> Now get the starting point of maximum length continuos unoccupied urinals by subtracting the last location by length - 1;
5 -> Now place the men in the middle of the starting and ending point
*/

//Code

//Include necessary header files for standard input and output
#include <iostream>

//Namespace to avoid variable collision
using namespace std;

//Main utility function
void placeKMensInNUrinalsUtil(int urinalSlots[], int nUrinals, int nMens)
{
    //Iterate over every men
    for (int men = 0; men < nMens; men++)
    {
        //Tracking variables with self explanatory names
        int maxContinuosEmptyUrinalsLength = 0;
        int currentContinuosEmptyUrinalsLength = 0;
        int lastPosmaxContinuosEmptyUrinalsLength = 0;

        //Iterate over every position in Urinals and get maximum length continuos unoccupied urinals and its last location in array
        for (int pos = 0; pos < nUrinals; pos++)
        {
            //For empty urinal increase length
            if (urinalSlots[pos] == 0)
            {
                currentContinuosEmptyUrinalsLength++;
            }
            //Update the tracking variables
            if (currentContinuosEmptyUrinalsLength >= maxContinuosEmptyUrinalsLength)
            {
                maxContinuosEmptyUrinalsLength = currentContinuosEmptyUrinalsLength;
                lastPosmaxContinuosEmptyUrinalsLength = pos;
            }

            //Reset the length when we found occupied urinal
            if (urinalSlots[pos] == 1)
            {
                currentContinuosEmptyUrinalsLength = 0;
            }
        }

        //Get starting postion and middle postion
        int startPosInTheLongestContinuosPathLength = lastPosmaxContinuosEmptyUrinalsLength - maxContinuosEmptyUrinalsLength + 1;
        int midPosInTheLongestContinuosPathLength = (startPosInTheLongestContinuosPathLength + lastPosmaxContinuosEmptyUrinalsLength) / 2;

        //Set/Occupy the Urinal
        urinalSlots[midPosInTheLongestContinuosPathLength] = 1;
    }
}

//Main Function
int main()
{
    //Get number of test cases
    int t;
    cin >> t;

    //Run the loop until t becomes 0 (0==false)
    while (t--)
    {
        //Get number of Urinals
        int nUrinals;
        cin >> nUrinals;

        //Get number of Mens
        int nMens;
        cin >> nMens;

        //Create binary array of Urinal slots of size nUrinals
        int urinalSlots[nUrinals];

        //Make every Urinal Unoccupied in starting (0 = Unoccupied  || 1 = Occupied)
        for (int i = 0; i < nUrinals; i++)
        {
            urinalSlots[i] = 0;
        }

        //Call the function
        placeKMensInNUrinalsUtil(urinalSlots, nUrinals, nMens);

        //Print the Urinals
        for (int i = 0; i < nUrinals; i++)
        {
            cout << urinalSlots[i] << "";
        }

        cout << endl;
    }

    //Yeah program executed successfully
    return 0;
}