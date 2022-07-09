// https://leetcode.com/problems/jump-game-vi/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0];
        list<pair<int, int>> d;
        d.push_back({nums[0], 0});
        for(int i = 1; i < (n - 1); ++i) {
            int new_el = d.front().first + nums[i];
            while(d.size() && (new_el > d.back().first)) d.pop_back();
            d.push_back({new_el, i});
            if(d.front().second<=(i-k)) d.pop_front();
        }
        return d.front().first + nums[n-1];
    }
};