// Author: TheGreatShubham
// Shubham Bansal
//Question :

/*
Algorithm

1. We calculate the maximum coins for every Index of the array by considering that last balloon remain at current index only between the range of left and right.
2. We simply insert two '1' in the array starting and ending of the array.Because Ballon[-1] & Balloon[n] will give outofBound error
3. Now we will run/iterate a loop for every index 1 to n.
4. For every index we just do the product of left ,right and current index.
5. Then, Do function call for left part before the current index of array, right value becomes  Index -1.
6. Range will become (left,index-1).
7. Similary, Do for the right part.Range will become (index+1,right).
8. Taking the sum of product , value come from left and right.
9. If left becomes greater than right then return 0;
10. If we will have calculated the value  for range of (left,right) then , we will store our result into DP.
11. If We have already calculated for range then simply return the value of DP[left][right]
12. we will repeat the 5-11 steps for every index and calculate the maximum value. 
 */

//CODE

// Include header file
#include <bits/stdc++.h>
using namespace std;

// Initializing  globally an 2D DP array
int dp[102][102];

// Our Utility function to calculate maximum coins after brusting
int maxCoinsUtility(int *arr, int left, int right)
{
    // This is a recursion breaking condition
    if (left > right)
        return 0;

    // If we have already calculated for the left and right index
    //  Then We will simply return our result.
    if (dp[left][right] != -1)
        return dp[left][right];

    // As we know that we want the maximum value that why we assign the minimum value to the ans variable.
    int ans = INT_MIN;

    // Lb is the index of the last balloon burst in (left, right)
    for (int lb = left; lb <= right; lb++)
    {
        // get the value of last balloon at index lb
        int currentBalloon = arr[lb];

        // the coins that burst will get are arr[left] * arr[lb] * arr[right]
        int tempAns = arr[left - 1] * arr[right + 1] * currentBalloon;

        // we also need to add the coins obtained from bursting balloons between left and lb, and between lb and right
        //i.e., dp[left][lb] and dp[lb][right]

        // Calculating DP[left][lb]
        int leftCoinsExcludingCurrentBalloon = maxCoinsUtility(arr, left, lb - 1);

        // Calculating DP[lb][right]
        int rightCoinsExcludingCurrentBalloon = maxCoinsUtility(arr, lb + 1, right);

        // calculate dp[left][right]
        tempAns += (leftCoinsExcludingCurrentBalloon + rightCoinsExcludingCurrentBalloon);

        // Taking the maximum value between new and previous one.
        ans = max(ans, tempAns);
    }

    // Basically Dp[left][right] represent the the maximum coins
    // we get after  burst all the balloons between left and right in the original array.
    return dp[left][right] = ans;
}

// This is our helper function
int getMaxCoins(int *arr, int n)
{
    // Call our Utility function
    return maxCoinsUtility(arr, 1, n);
}

// Main function starts from here
int main()
{
    // t is the number of test cases
    int t;
    cin >> t;

    //Here, we are solving the testcase one by one
    while (t--)
    {
        // Taking input  of total number of balloons
        int nBalloons;
        cin >> nBalloons;

        // Initializing an array
        int balloonCoins[nBalloons + 2];

        // Adding 1 in the fist and last position of the array because for the first position and last position
        // Do not have first-1 and last+1 respectively.
        balloonCoins[0] = balloonCoins[nBalloons + 1] = 1;

        // Taking value of Coins of balloons which will get after brust
        for (int i = 1; i <= nBalloons; i++)
        {
            cin >> balloonCoins[i];
        }

        // Putting all values in DP array is -1
        for (int i = 0; i < 102; i++)
        {
            for (int j = 0; j < 102; j++)
            {
                dp[i][j] = -1;
            }
        }

        // Call our helper function "getMaxcoins" to Calculate the
        //  maximum coins we can collect by bursting the balloons wisely
        cout << getMaxCoins(balloonCoins, nBalloons) << endl;
    }
}
