#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;


//"hit" -> "hot" -> "dot" -> "dog" -> "cog",

struct Graph
{
public:
	string vals;
	vector<Graph*> edges;
	int color;
	int dis;

	Graph(string str) : vals(str), color(0), dis(INT_MAX) {}

};

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> rtValue;
		vector<string> container;
		wordList.push_back(beginWord);
		int min = 1;
		Graph* src, *dst;
		set<Graph*> gSet;
		for (auto& w : wordList)
		{
			Graph *node = new Graph(w);
			if (w == beginWord)	src = node;
			if (w == endWord)   dst = node;
			gSet.insert(node);
		}

		for (auto &item : gSet)
			for (auto &e : gSet)
				if (findDiff(item->vals, e->vals) == 1)
					item->edges.push_back(e);

		deque<Graph*> origin, next;
		origin.push_back(src);
		src->dis = 1;
		while (!origin.empty() && !contains(origin, endWord))
		{
			while (!origin.empty())
			{
				Graph*& g = origin.front();
				origin.pop_front();
				g->color = 1;
				for (auto &t : g->edges)
					if (t->color != 1)
					{
						t->dis = min+1 < t->dis ? min+1 : t->dis;
						next.push_back(t);
					}
			}
			min++;

			origin = next;
			next.clear();
		}
		if (origin.empty())
			return rtValue;

		Graph* g = nullptr;
		for (auto& e: origin)
			if (e->vals == endWord)
			{
				g = e;
				break;
			}

		
		container.push_back(g->vals);
		graph_DFS(rtValue, container, beginWord, g);
		for (auto& item : rtValue)
			reverse(begin(item), end(item));

		return rtValue;
    }

	int findDiff(string s1, string s2)
	{
		int diff = 0;
		for (int i = 0; i  < s1.size(); ++i)
			if (s1[i] != s2[i])
				diff ++;

		return diff;
	}

	bool contains(deque<Graph*> &graph, string endWord)
	{
		for (auto g : graph)
			if (g->vals == endWord)
				return true;

		return false;
	}

	void graph_DFS(vector<vector<string>>& rtValue, vector<string>& container, string& word, Graph* src)
	{
		if (src->vals == word)
		{
			rtValue.push_back(container);
			return;
		}

		for (auto& item : src->edges)
		{
			if (item->dis != src->dis - 1)
				continue;

			container.push_back(item->vals);
			graph_DFS(rtValue, container, word, item);
			container.pop_back();
		}
	}
};

//class Solution {
//public:
//    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//		vector<vector<string>> rtValue;
//		vector<string> container;
//		int ideal_min = INT_MAX;
//		int length = 1;
//		wordList.push_back(beginWord);
//		int min = 1;
//		Graph* src;
//		set<Graph*> gSet;
//		for (auto& w : wordList)
//		{			Graph *node = new Graph(w);
//			if (w == beginWord)	src = node;
//			gSet.insert(node);
//		}
//
//		for (auto &item : gSet)
//			for (auto &e : gSet)
//				if (findDiff(item->vals, e->vals) == 1)
//					item->edges.push_back(e);
//
//		container.push_back(src->vals);
//		graph_DFS(rtValue, container, endWord, src, ideal_min, length);
//		
//		vector<vector<string>> values;
//		int minN = INT_MAX;
//		for (auto &e : rtValue)
//			if (e.size() < minN)
//				minN = e.size();
//
//		for (auto &e : rtValue)
//			if (e.size() == minN)
//				values.push_back(e);
//
//		return rtValue;
//    }
//
//	void graph_DFS(vector<vector<string>>& rtValue, vector<string>& container, string& word, Graph* src, int& ideal, int length)
//	{
//		if (length > ideal)
//			return;
//		if (src->vals == word)
//		{
//			ideal = min(length, ideal);
//			rtValue.push_back(container);
//			return;
//		}
//
//		for (auto& item : src->edges)
//		{
//			if(item->color == 1)
//				continue;
//
//			item->color = 1;
//			container.push_back(item->vals);
//			graph_DFS(rtValue, container, word, item, ideal, length+1);
//			container.pop_back();
//			item->color = 0;
//		}
//	}
//
//	int findDiff(string s1, string s2)
//	{
//		int diff = 0;
//		for (int i = 0; i  < s1.size(); ++i)
//			if (s1[i] != s2[i])
//				diff ++;
//
//		return diff;
//	}
//
//	bool contains(deque<Graph*> &graph, string endWord)
//	{
//		for (auto g : graph)
//			if (g->vals == endWord)
//				return true;
//
//		return false;
//	}
//};


int main()
{
	Solution s;
	string stringss[] = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
	string a = "cet";
	string b = "ism";
	vector<string> strs(begin(stringss), end(stringss));
	vector<vector<string>> strstr =  s.findLadders(a, b, strs);
	for (auto e: strstr)
	{
		for (auto l : e)
			cout << l << " ";
		cout << endl;
	}
}

	//string stringss[] = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
	//string a = "cet";
	//string b = "ism";
	//string stringss[] = {"hot","dot","dog","lot","log","cog"};
	//string a = "hit";
	//string b = "cog";