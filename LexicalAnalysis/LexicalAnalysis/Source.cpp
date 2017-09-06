#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <fstream>
#include <deque>
using namespace std;

#define DEBUG 

class Solution
{
public:
	map<string, string> lexicalNormalization;

	Solution()
	{
		init();
	}

	void lexicalAnalysis(multimap<string, string>& _output,	string context)
	{
		replace(begin(context), end(context), '\n', ' ');
		replace(begin(context), end(context), '\t', ' ');
		int lensrc = context.find_first_not_of(" ");
		int step = 1;
		string word = "";
		vector<string> wordList;

		for (int i = lensrc; i < context.size(); i+=step)
		{
			step = 1;
			if (context[i] != ' ')	word += context[i];
			else
			{
				step = 	countSpace(i, context);
				wordList.push_back(word);
				word.clear();
			}
		}
		if (!word.empty())
			wordList.push_back(word);

#ifdef DEBUG
		//for (const auto& e : wordList)
		//	cout << e << " ";
		//cout << endl;
#endif

		clarifyType(wordList, _output);
#ifdef DEBUG
		for (const auto& e : _output)
			cout << "( " << e.first << "," << e.second << " )" << endl;
		cout << endl;
#endif
	}

	void clarifyType(vector<string>& wordList, multimap<string, string>& _output)
	{
		int dex = 0;
		for (const auto& e : wordList)
		{
			if (dex == 0 && contains(e, "关键字"))	_output.insert(pair<string, string>("关键字", e));
			else if (dex == 0 && contains(e, "双界符"))	_output.insert(pair<string, string>("双界符", e));
			else if (contains(e, "注释")){
				_output.insert(pair<string, string>("注释", e));
				dex = (dex+1) % 2;
			}
			else if (dex == 0 && contains(e, "单界符"))	_output.insert(pair<string, string>("单界符", e));
			else if (dex == 0 && bConstantString(e))	_output.insert(pair<string, string>("字符常数", e));
			else if (dex == 0 && judgeNumer(0, e))	_output.insert(pair<string, string>("整常数", e));
			else if (dex == 0 && judgeFloat(0, e))	_output.insert(pair<string, string>("浮点数", e));
			else if (dex == 0) _output.insert(pair<string, string>("标识符", e));
		}
	}

	int countSpace(int index, const string& context)
	{
		int N = 0;
		for (int i = 0; i < context.size(); ++i)
			if (context[index+i] == ' ')
				++N;
			else break;

		return N;
	}

	bool judgeNumer(int i, const string& str)
	{
		if (!str.empty() && i == 0 && str[i] == '-')
			return judgeNumer(i+1, str);

		if (str.size() == i)
			return true;

		if (str[i] < '0' || str[i] > '9')
			return false;

		return judgeNumer(i+1, str);
	}

	bool judgeFloat(int i, const string& str)
	{
		//int record = 0;
		if (!str.empty() && i == 0 && str[i] == '-')
			return judgeFloat(i+1, str);

		if (str.size() == i)
			return true;

		if (str[i] < '0' || str[i] > '9')
			if (str[i] == '.')
			{
				//record = 1;
				return judgeFloat(i+1, str);
			}
			else return false;

		return judgeFloat(i+1, str);
	}

	bool contains(const string& e, const string &type)
	{
		string str = lexicalNormalization[type], word;
		stringstream ss(str);
		
		while (ss >> word)
			if (word == e)
				return true;

		ss.clear();
		return false;
	}

	bool bConstantString(const string& str)
	{
		if (!str.empty() && str[0] == '\"' && str[str.size() - 1] == '\"')
			return true;

		return false;
	}

	void init()
	{
		lexicalNormalization.insert(pair<string, string>("标识符", ".*"));
		lexicalNormalization.insert(pair<string, string>("关键字", "cout int string char float main if when while for break else return for"));
		lexicalNormalization.insert(pair<string, string>("整常数", "[0-9].*"));
		lexicalNormalization.insert(pair<string, string>("字符常数", "\".*\""));
		lexicalNormalization.insert(pair<string, string>("浮点常数", "[0-9].*\.[0-9]"));
		lexicalNormalization.insert(pair<string, string>("单界符", "( ) { } + - * / ; . , : [ ]"));
		lexicalNormalization.insert(pair<string, string>("双界符", "/= += -= *= :="));
		lexicalNormalization.insert(pair<string, string>("注释", "// /* */"));
	}
};

int main()
{
	Solution s;
	multimap<string, string> lexicalMap;
	ifstream in("test.txt");
	if (!in.is_open())
	{
		cout << "File OutPut Error" << endl;
		return 0xff;
	}

	stringstream buffer;
	buffer << in.rdbuf();

	cout << buffer.str() << endl;

	s.lexicalAnalysis(lexicalMap, buffer.str());
}