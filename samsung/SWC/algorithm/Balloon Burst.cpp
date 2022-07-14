// Author: TheGreatShubham
// Shubham Bansal
//Que Link : https://leetcode.com/problems/burst-balloons/

/*
Algorithm


*/

//CODE
class Solution {
public:
    vector<vector<int>>dp;
    int google(vector<int>& nums,int left,int right){
        if(left>right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];
        int ans=INT_MIN;
        for(int lb=left;lb<=right;lb++){
            int tempans=nums[left-1]*nums[right+1]*nums[lb];
            int x = google(nums,left,lb-1);
            int y = google(nums,lb+1,right);
            tempans+=(x+y);
            ans=max(ans,tempans);
        }
         return dp[left][right]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp=vector<vector<int>>(n+2,vector<int>(n+2,-1));
        
        return google(nums,1,n);
    }
};
