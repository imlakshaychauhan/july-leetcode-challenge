// https://leetcode.com/problems/number-of-matching-subsequences/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mp(26);
        int n = s.length();
        for(int i = 0; i < n; i++) mp[s[i] - 'a'].push_back(i);
        int ans = words.size();
        for(auto& word : words) {
            int last = -1;
            for(char c : word) {
                auto& cIndexes = mp[c - 'a'];
                auto it = upper_bound(cIndexes.begin(), cIndexes.end(), last);
                if(it == cIndexes.end()) {
                    ans--;
                    break;
                } 
                else last = *it;
            }
        }
        return ans;
    }
};