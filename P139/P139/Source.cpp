#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++){
            for (int j = 0; j < i; j++){
                dp[i] = dp[j] && (find(wordDict.begin(),  wordDict.end(), s.substr(j, i-j)) != wordDict.end());
                if (dp[i])
                    break;
            }
        }
        
        return dp[s.size()];
    }
};