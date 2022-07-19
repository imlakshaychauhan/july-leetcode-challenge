// https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    if (numRows == 1) return ans;
    for (int i = 1; i < numRows; i++) {
        vector<int> vec;
        vec.push_back(1);
        for (int j = 1; j < i; j++)
            vec.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        vec.push_back(1);
        ans.push_back(vec);
    }
        return ans;
    }
};