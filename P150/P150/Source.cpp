#include<ctype.h>
#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> algos;
        int i = 0;
        while(i != tokens.size()){
            string c = tokens[i];
            
            if (c!="+" && c!="-" && c!="*" && c!="/"){
                algos.push(c);
                i++;
                continue;
            }
            string op1 = algos.top();
            algos.pop();
            string op2 = algos.top();
            algos.pop();
            switch(c[0])
            {
                case '+':    
                    algos.push(to_string(atoi(op1.c_str()) + atoi(op2.c_str())));
                    break;
                case '-':
                    algos.push(to_string(atoi(op2.c_str()) - atoi(op1.c_str())));
                    break;
                case '*':
                    algos.push(to_string(atoi(op1.c_str()) * atoi(op2.c_str())));
                    break;
                case '/':
                    algos.push(to_string(atoi(op2.c_str()) / atoi(op1.c_str())));
                    break;
            }
            i++;
        }
        
        return atoi(algos.top().c_str());
    }
};