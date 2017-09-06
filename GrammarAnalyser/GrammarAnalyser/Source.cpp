#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <sstream>
#include <map>
using namespace std;

// id -> number

class GrammarAnalyser
{
public:
	GrammarAnalyser(const string &context) : inputstream(context + "#"), ip(0)	{ grams.push("#"); status.push("0"); }

	//LR分析
	void LR_Analyses(vector<string>& __products, vector<map<string, string>>& actions, vector<map<string, string>>& gotos, vector<string>& E)
	{
		stack<string> vals;	//数字栈
		while (ip < inputstream.size())
		{
			int curStatus = atoi(status.top().c_str());
			stringstream ss;
			ss.clear();ss.flush();
			ss << inputstream[ip];
			string c;
			ss >> c;
			if (c.size() > 0 && c[0] >= '0' && c[0] <= '9')
			{
				vals.push(c);	//语义部分压栈
				c = "id";
			}
			if (belong2S(actions[curStatus][c]))
			{
				string stackInfo = "";
				stack<string> tmpStack = grams;
				stack<string> tmpSysStack = status;
				while (!tmpStack.empty())
				{
					stackInfo += tmpStack.top();
					tmpStack.pop();
				}
				while (!tmpSysStack.empty())
				{
					stackInfo += tmpSysStack.top();
					tmpSysStack.pop();
				}

				grams.push(c);
				ss.clear();
				ss << actions[curStatus][c][1];
				string tmp;
				ss >> tmp;
				status.push(tmp);

				reverse(stackInfo.begin(), stackInfo.end());
				//__products.push_back("栈: " + stackInfo + "   ," + inputstream.substr(ip) + "[移进]");
			}
			else if (belong2R(actions[curStatus][c]))
			{
				string stackInfo = "";
				stack<string> tmpStack = grams;
				stack<string> tmpSysStack = status;
				while (!tmpStack.empty())
				{
					stackInfo += tmpStack.top();
					tmpStack.pop();
				}
				while (!tmpSysStack.empty())
				{
					stackInfo += tmpSysStack.top();
					tmpSysStack.pop();
				}
				

				int index = actions[curStatus][c][1] - 48;
				string right = findRight(E[index]);
				//=========================================================================> 语义分析部分
				if (right.size() == 1 || right == "id")
				{
					cout << "ASSIGN\t(" << findLeft(E[index]) << ")" <<  vals.top() << "\tNULL" << endl;
				}
				else
				{
					string num1 = vals.top(); vals.pop();
					string num2 = vals.top(); vals.pop();
					cout << findRight(E[index])[1] << "\t" << num1 << "\t" << num2 << endl;
					if (findRight(E[index])[1] == '*')
						vals.push(to_string(atoi(num1.c_str()) * atoi(num2.c_str())));
					else
						vals.push(to_string(atoi(num1.c_str()) + atoi(num2.c_str())));
				}
				//=========================================================================< 语义分析部分结束
				int size;
				if (right == "id")
					size = 1;
				else
				    size = right.size();
				while (size--)
				{
					grams.pop();
					status.pop();
				}
				
				tmpSysStack = status;
				
				string sss = "";

				int cur = atoi(status.top().c_str());
				string sysm = findLeft(E[(int)actions[curStatus][c][1] - 48]);
				grams.push(sysm);
				status.push(gotos[cur][sysm]);

				tmpStack = grams;
				while (!tmpStack.empty())
				{
					sss += tmpStack.top();
					tmpStack.pop();
				}
				while (!tmpSysStack.empty())
				{
					sss += tmpSysStack.top();
					tmpSysStack.pop();
				}

				reverse(stackInfo.begin(), stackInfo.end());
				//__products.push_back("栈: " + stackInfo + "   ," + sysm + "->" + right + "   ," + inputstream.substr(ip) + "[规约]");
				__products.push_back(sysm + "->" + right);

				reverse(sss.begin(), sss.end());
				//__products.push_back("栈: " + sss + "   ,"+ inputstream.substr(ip) + "[goto]");
				continue;
			}
			else if(actions[curStatus][c] == "acc")
			{
				__products.push_back("接受");
				cout << "ACC\t" << vals.top() << endl;
				return;
			}
			else
			{
				error();	
			}
			ip++;
		}
	}
		
	//出错处理
	void error()
	{
		cout << "Error" << endl;
		exit(0xff);
	}

	//判断是否属于移近项目
	bool belong2S(const string& s)
	{
		return (toLowerCase(s).find_first_of("s") != string::npos);
	}

	//判断是否属于规约项目
	bool belong2R(const string& s)
	{
		return (toLowerCase(s).find_first_of("r") != string::npos);
	}

	//给出右部产生式（去除空格）
	string findRight(string E)
	{
		string e = E.substr(E.find_first_of("->") + 2);
		stringstream ss(e);
		string s = "";
		string tmp;
		while (ss >> tmp)
			s += tmp;

		return s;
	}

	//给出左部产生式（去除空格）
	string findLeft(string E)
	{
		string e = E.substr(0, E.find_first_of("->"));
		stringstream ss(e);
		string s = "";
		string tmp;
		while (ss >> tmp)
			s += tmp;
		
		return s;
	}

	//将所有字符串转变成小写
	string toLowerCase(string s)
	{
		if ((int)s[0] >= 65 && (int)s[0] <= 106)
		{
			s[0] = s[0] - ('A' - 'a');
			stringstream ss(s);
			return ss.str();
		}
		return s;
	}

private:
	stack<string> grams;//语法栈
	stack<string> status;	//状态栈
	stringstream ss;	//输入流
	string inputstream;	//识别字符流
	int ip;	//指针
};

int main()
{
	// ================ Actions ==========================
	/*vector<map<string, string>> actions(7);
	actions[0].insert(pair<string, string>("a", "S3"));
	actions[0].insert(pair<string, string>("b", "S4"));
	actions[1].insert(pair<string, string>("#", "acc"));
	actions[2].insert(pair<string, string>("a", "S3"));
	actions[2].insert(pair<string, string>("b", "S4"));
	actions[3].insert(pair<string, string>("a", "S3"));
	actions[3].insert(pair<string, string>("b", "S4"));
	actions[4].insert(pair<string, string>("a", "R3"));
	actions[4].insert(pair<string, string>("b", "R3"));
	actions[4].insert(pair<string, string>("#", "R3"));
	actions[5].insert(pair<string, string>("a", "R1"));
	actions[5].insert(pair<string, string>("b", "R1"));
	actions[5].insert(pair<string, string>("#", "R1"));
	actions[6].insert(pair<string, string>("a", "R2"));
	actions[6].insert(pair<string, string>("b", "R2"));
	actions[6].insert(pair<string, string>("#", "R2"));
*/
	vector<map<string,string>> actions(12);
	actions[0].insert(pair<string, string>("(", "S4"));
	actions[0].insert(pair<string, string>("id", "S5"));
	actions[1].insert(pair<string, string>("+", "S7"));
	actions[1].insert(pair<string, string>("#", "acc"));
	actions[2].insert(pair<string, string>("+", "R2"));
	actions[2].insert(pair<string, string>("*", "S6"));
	actions[2].insert(pair<string, string>(")", "R2"));
	actions[2].insert(pair<string, string>("#", "R2"));
	actions[3].insert(pair<string, string>("+", "R4"));
	actions[3].insert(pair<string, string>("*", "R4"));
	actions[3].insert(pair<string, string>(")", "R4"));
	actions[3].insert(pair<string, string>("#", "R4"));
	actions[4].insert(pair<string, string>("(", "S4"));
	actions[4].insert(pair<string, string>("id", "S5"));
	actions[5].insert(pair<string, string>("+", "R6"));
	actions[5].insert(pair<string ,string>("*", "R6"));
	actions[5].insert(pair<string, string>(")", "R6"));
	actions[5].insert(pair<string, string>("#", "R6"));
	actions[6].insert(pair<string, string>("(", "S4"));
	actions[6].insert(pair<string, string>("id", "S5"));
	actions[7].insert(pair<string, string>("(", "S4"));
	actions[7].insert(pair<string, string>("id", "S5"));
	actions[8].insert(pair<string, string>("+", "R3"));
	actions[8].insert(pair<string, string>("*", "R3"));
	actions[8].insert(pair<string, string>(")", "R3"));
	actions[8].insert(pair<string, string>("#", "R3"));
	actions[9].insert(pair<string, string>("+", "R1"));
	actions[9].insert(pair<string, string>("*", "S6"));
	actions[9].insert(pair<string, string>(")", "R1"));
	actions[9].insert(pair<string, string>("#", "R1"));
	actions[10].insert(pair<string, string>("+", "S7"));
	actions[10].insert(pair<string, string>(")", "S11"));
	actions[11].insert(pair<string, string>("+", "R5"));
	actions[11].insert(pair<string, string>("*", "R5"));
	actions[11].insert(pair<string, string>(")", "R5"));
	actions[11].insert(pair<string, string>("#", "R5"));

	// ================ Gotos ===========================
	/*vector<map<string ,string>> gotos(7);
	gotos[0].insert(pair<string, string>("S", "1"));
	gotos[0].insert(pair<string, string>("B", "2"));
	gotos[2].insert(pair<string, string>("B", "5"));
	gotos[3].insert(pair<string, string>("B", "6"));*/
	vector<map<string, string>> gotos(12);
	gotos[0].insert(pair<string, string>("E", "1"));
	gotos[0].insert(pair<string, string>("T", "2"));
	gotos[0].insert(pair<string, string>("F", "3"));
	gotos[4].insert(pair<string, string>("E", "10"));
	gotos[4].insert(pair<string, string>("T", "2"));
	gotos[4].insert(pair<string, string>("F", "3"));
	gotos[6].insert(pair<string, string>("F", "8"));
	gotos[7].insert(pair<string, string>("T", "9"));
	gotos[7].insert(pair<string, string>("F", "3"));

	// ================ Productss ========================
	vector<string> E;
	E.push_back("");
	/*E.push_back("S -> BB");
	E.push_back("B -> aB");
	E.push_back("B -> b");*/
	E.push_back("E -> E + T");
	E.push_back("E -> T");
	E.push_back("T -> T * F");
	E.push_back("T -> F");
	E.push_back("F -> (E)");
	E.push_back("F -> id");
	
	// ================ Input Stream ========================
	//string context = "bab";
	string context = "6+7*8";

	// ================ LR Analyser Start ===================>
	cout << "6+7*8" << endl <<endl;
	GrammarAnalyser gram(context);
	vector<string> products;		//  规约式
	gram.LR_Analyses(products, actions, gotos, E);
	
	// ================ LR Analyser End =====================<


	// ================ Outpu ================================
	cout<<endl;
	for(const auto& p: products)
		cout << p <<endl;
}