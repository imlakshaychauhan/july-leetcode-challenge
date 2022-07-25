// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    int bSearch(vector<int>& nums, int target, bool leftBias) {
        int l = 0, h = nums.size() - 1;
        int ans = -1;
        while(l <= h) {
            int mid = (l + h) / 2;
            if(target > nums[mid])
                l = mid + 1;
            else if(target < nums[mid])
                h = mid - 1;
            else {
                ans = mid;
                if(leftBias)
                    h = mid - 1;
                else 
                    l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = bSearch(nums, target, true);
        int right = bSearch(nums, target, false);
        return {left, right};
    }
};