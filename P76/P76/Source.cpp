#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//30.29%

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> srcHash;
        // 记录目标字符串每个字母出现次数
        for (auto e: t)
            srcHash[e]++;
            
        int start = 0,i= 0;
        // 用于记录窗口内每个字母出现次数 
        unordered_map<char, int> destHash;
        int found = 0;
        int begin = -1, end = s.size(), minLength = s.size();
        for(start = i = 0; i < s.size(); i++){
            // 每来一个字符给它的出现次数加1
            destHash[s.at(i)]++;
            // 如果加1后这个字符的数量不超过目标串中该字符的数量，则找到了一个匹配字符
            if(destHash[s[i]] <= srcHash[s[i]]) found++;
            // 如果找到的匹配字符数等于目标串长度，说明找到了一个符合要求的子串    
            if(found == t.size()){
                // 将开头没用的都跳过，没用是指该字符出现次数超过了目标串中出现的次数，并把它们出现次数都减1
                while(start < i && destHash[s[start]] > srcHash[s[start]]){
                    destHash[s[start]]--;
                    start++;
                }
                // 这时候start指向该子串开头的字母，判断该子串长度
                if(i - start < minLength){
                    minLength = i - start;
                    begin = start;
                    end = i;
                }
                // 把开头的这个匹配字符跳过，并将匹配字符数减1
                destHash[s[start]]--;
                found--;
                // 子串起始位置加1，我们开始看下一个子串了
                start++;
            }
        }
        // 如果begin没有修改过，返回空
        return begin == -1 ? "" : s.substr(begin,end - begin + 1);
    }
};


int main()
{
	Solution s;
	cout << s.minWindow("a", "b") << endl;
	return 0;
}