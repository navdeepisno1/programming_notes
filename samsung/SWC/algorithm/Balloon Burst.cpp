// Author: TheGreatShubham
// Shubham Bansal
//Que Link : https://leetcode.com/problems/burst-balloons/

/*
Algorithm


*/

//CODE
#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
int maxCoinsUtility(int *arr, int left, int right)
{
    if (left > right)
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];
    int ans = INT_MIN;
    for (int lb = left; lb <= right; lb++)
    {
				int currentBalloon = arr[lb];        
				
				int tempAns = arr[left - 1] * arr[right + 1] * currentBalloon;
        
				int leftCoinsExcludingCurrentBalloon = google(arr, left, lb - 1);
        int rightCoinsExcludingCurrentBalloon = google(arr, lb + 1, right);
			
        tempAns += (leftCoinsExcludingCurrentBalloon + rightCoinsExcludingCurrentBalloon );
			
        ans = max(ans, tempAns);
    }
    return dp[left][right] = ans;
}
int getMaxCoins(int *arr, int n)
{
    return maxCoinsUtility(arr, 1, n);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int nBalloons;
        cin >> nBalloons;
        int balloonCoins[nBalloons + 2];
        balloonCoins[0] = balloonCoins[nBalloons + 1] = 1;
        for (int i = 1; i <= nBalloons; i++)
        {
            cin >> balloonCoins[i];
        }
        for(int i=0;i<102;i++){
		for(int j=0;j<102;j++){
			dp[i][j]=-1;
		}
	}
        cout << getMaxCoins(balloonCoins, nCoins);
    }
}
