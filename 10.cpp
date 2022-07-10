// https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = 0, y = 0;
        int n = cost.size();
        for(int i = 0; i < n; i++) {
            int temp = cost[i] + min(x, y);
            y = x;
            x = temp;
        }
        return min(x, y);
    }
};