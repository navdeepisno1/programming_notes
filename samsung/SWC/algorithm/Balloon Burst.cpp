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
int google(int *arr, int left, int right)
{
    if (left > right)
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];
    int ans = INT_MIN;
    for (int lb = left; lb <= right; lb++)
    {
        int tempans = arr[left - 1] * arr[right + 1] * arr[lb];
        int x = google(arr, left, lb - 1);
        int y = google(arr, lb + 1, right);
        tempans += (x + y);
        ans = max(ans, tempans);
    }
    return dp[left][right] = ans;
}
int maxCoins(int *arr, int n)
{
    return google(arr, 1, n);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n + 2];
        arr[0] = arr[n + 1] = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        cout << maxCoins(arr, n);
    }
}
