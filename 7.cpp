// https://leetcode.com/problems/interleaving-string/
class Solution {
public:
    bool f(string &s1,string &s2,string &s3,int i, int j, int k,vector<vector<int>> &dp){
		if((i == s1.size()) && (j == s2.size())) return true;
		if(dp[i][j] != -1) return dp[i][j];
		if(i < s1.size() && s1[i] == s3[k])
			if(f(s1, s2, s3, i+1, j, k+1, dp)) return dp[i + 1][j] = true;
		if(j < s2.size() && s2[j] == s3[k])
			if(f(s1, s2, s3, i, j+1, k+1, dp)) return dp[i][j + 1] = true;
		return dp[i][j] = false;
	}
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size(), n = s2.size(), p = s3.size();
		vector<vector<int>> dp(101, vector<int>(101, -1));
		if(p != (m + n)) return false;
		return f(s1, s2, s3, 0, 0, 0, dp);
	}
};