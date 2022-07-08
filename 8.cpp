// https://leetcode.com/problems/paint-house-iii/
class Solution {
public:
    int f(int ind,int prev,int cnt,vector<int>& houses, vector<vector<int>>& cost,int target, vector<vector<vector<int>>> &dp ) {
        if(ind == houses.size() && cnt == target) return 0;
        if(ind == houses.size() && (cnt < target || cnt > target)) return 1e9;
        if(cnt > target) return 1e9;
        if(dp[ind][prev][cnt] != -1) return dp[ind][prev][cnt];
        
        int ans = INT_MAX;
        if(houses[ind] != 0){
            if(houses[ind] != prev)
                ans = 0 + f(ind + 1, houses[ind], cnt + 1, houses, cost, target, dp);
            else ans = 0 + f(ind + 1, houses[ind], cnt, houses, cost, target, dp);
            return dp[ind][prev][cnt] = ans;
        } 
        
        for(int i = 0; i < cost[0].size(); ++i)
            if(i + 1 != prev){
                int temp = cost[ind][i] + f(ind + 1,i + 1, cnt + 1, houses, cost, target, dp);
                ans = min(ans, temp);
            }
            else {
                int temp = cost[ind][i] + f(ind + 1, prev, cnt, houses, cost, target, dp);
                ans = min(ans, temp);
            }
        return dp[ind][prev][cnt] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(21, vector<int>(target + 1, -1)));
        int ans = f(0, 0, 0, houses, cost, target, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};