// https://leetcode.com/problems/range-sum-query-mutable/
class NumArray {
public:
    int* array;
    int size = 0, sum = 0;
    NumArray(vector<int>& nums) {
        array = &nums[0];
        size = nums.size();
        for (int i = 0; i < size; ++i) sum += array[i];
    }
    
    void update(int index, int val) {
        sum += (val- array[index]);
        array[index] = val;
    }
    
    int sumRange(int left, int right) {
        int ans = sum; 
        for (int i = 0; i < left; ++i)
            ans -= array[i];
        for (int i = right + 1; i < size; ++i)
            ans -= array[i];
        return ans;
    }
};