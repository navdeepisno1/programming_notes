//Author: navdeepisno1
//Navdeep Sharma

/*
Algorithm

Basic Approach : For every number check if it is ominous number and print total count

*/

//CODE

//Important Header Files
#include <iostream>

//Namespace to remove naming conflict
using namespace std;

//Utility Function
int getTotalProducts(int nStart, int nEnd, int k, int DigitDelete[], int n)
{
    //Declare and Initalise Count
    int count = 0;

    //Hashmap to store the count of digits in the number
    int DIGITS_MAP[10];

    //Iterate over every number from start to end
    for (int i = nStart; i < nEnd; i++)
    {
        //Set every digit count in hashmap to 0
        for (int i = 0; i < 10; i++)
        {
            DIGITS_MAP[i] = 0;
        }

        int nCurr = i;
        while (nCurr > 0)
        {
            //Use modulus to get last number
            int rem = nCurr % 10;

            //Increase Digit count in map
            DIGITS_MAP[rem]++;

            //Remove last number by dividing by 10
            nCurr /= 10;
        }

        //Variable to track Rouge Numbers
        int rougeNumber = 0;
        for (int i = 0; i < n; i++)
        {
            rougeNumber += DIGITS_MAP[DigitDelete[i]];
        }

        if (rougeNumber < k)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    //Get testcases
    int t;
    cin >> t;

    while (t--)
    {
        //Get start ,end and K
        int nStart, nEnd, k;

        cin >> nStart >> nEnd >> k;

        int n;
        cin >> n;

        int DigitDelete[n];
        for (int i = 0; i < n; i++)
        {
            cin >> DigitDelete[i];
        }

        cout << getTotalProducts(nStart, nEnd, k, DigitDelete, n) << endl;
    }

    return 0;
}