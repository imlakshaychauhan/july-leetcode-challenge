// https://leetcode.com/problems/wiggle-subsequence/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        
        int prev = nums[1]-nums[0];
        int count;
        if(prev != 0) count = 2;
        else count = 1;
        
        for(int i=2; i<nums.size(); i++)
        {
            int diff = nums[i]-nums[i-1];
            if( (diff<0 && prev>=0) || (diff>0 && prev<=0) )
            {
                count++;
                prev = diff;
            }
        }
        return count;
    }
};