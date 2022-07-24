// https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int r = 0, c = n - 1;
        while(r < m && c >= 0)
            if(matrix[r][c] == target) 
                return true;
            else if(matrix[r][c] < target) 
                r++;
            else 
                c--;
        return false;
    }
};