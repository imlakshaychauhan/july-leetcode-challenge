// https://leetcode.com/problems/find-and-replace-pattern/
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int len = words[0].size();
        
        for(auto &word : words){
            
            int hash1[26], hash2[26];
            bool flag = true;
            memset(hash1, -1, sizeof(hash1));
            memset(hash2, -1, sizeof(hash2));

            for(int i = 0; i < len; i++)
                if( hash1[pattern[i] - 'a'] == -1 && hash2[word[i]-'a'] == -1 ){
                    hash1[pattern[i] - 'a'] = word[i] - 'a';
                    hash2[word[i] - 'a'] = pattern[i] - 'a';
                }
                else if( hash1[pattern[i] - 'a'] != (word[i] - 'a') ){
                    flag = false;
                    break;
                }
            if(flag) 
                ans.push_back(word);
        }
        
        return ans;
    }
};