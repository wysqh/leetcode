#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


struct Member
{
	int id;
	int gender;
	int height;

	Member(int _id, int _gender, int _height) : id(_id), gender(_gender), height(_height)
	{
	}
};

bool compare(const Member& a, const Member& b)
{
	return a.height < b.height;
}

class Solution
{
public:
	int findWinner(vector<Member> members, int dot, int id)
	{
		vector<bool> failed(members.size(), false);
		int currentdotId = id;
		while (countExist(failed) != 1)
		{
			currentdotId = currentdotId+1 >= members.size() ? 0 : currentdotId + 1;
			while (failed[currentdotId])
					currentdotId = currentdotId + 1 >= members.size()? 0 : currentdotId + 1;
			int tmp = dot;
			while (tmp != 0)
			{
				while (failed[currentdotId])
					currentdotId = currentdotId + 1 >= members.size()? 0 : currentdotId + 1;
				tmp--;
			}
			failed[currentdotId] = true;
		}

		return getIdByIndex(failed, members);
	}

	int countExist(vector<bool> fails)
	{
		int cnt = 0;
		for (const auto& e: fails)
			if (e == false)
				cnt++;

		return cnt;
	}

	int getIdByIndex(const vector<bool>& fails, const vector<Member>& members)
	{
		int id = -1;
		int index = 0;
		for (int i = 0; i < fails.size(); i++)
			if (fails[i] == false){
				id  = members[i].id;
				break;
			}

		return id;
	}
};


int main()
{
	string s1 = "ab";
	if (s1[3] == '\0')
		cout << "sdad";
	int n;
	cin >> n;
	vector<Member> members;
	while (n-- > 0)
	{
		 int id;
		 string gender;
		 int height;
		 cin >> id >> gender >> height;
		 if (gender == "FEMALE")
			 members.push_back(Member(id, 0,  height));
		 else
			 members.push_back(Member(id, 1, height));
	}
	int dot;
	cin >> dot;
	vector<Member> females;
	vector<Member> males;
	for (const auto& e: members)
		if (e.gender == 0)
			females.push_back(e);

	for (const auto& e: members)
		if (e.gender == 1)
			males.push_back(e);

	int src = 0, dst = src + 1;
	while (dst < females.size())
	{
		while(dst < females.size() && females[src].height == females[dst].height)
			dst++;

		if (src != dst)
		{
			reverse(females.begin() + src, females.begin() + dst);
		}
		src = dst + 1;
		dst = src;
	}
	src = 0, dst = src + 1;
	while (dst < males.size())
	{
		while(dst < males.size() && males[src].height == males[dst].height)
			dst++;

		if (src != dst)
		{
			reverse(males.begin() + src, males.begin() + dst);
		}
		src = dst + 1;
		dst = src;
	}
	members.clear();
	stable_sort(begin(females), end(females), compare);
	stable_sort(begin(males), end(males), compare);

	for (const auto& e: females)
		members.push_back(e);
	for (const auto& e: males)
		members.push_back(e);

	Solution solution;
	cout << solution.findWinner(members, dot, females[females.size()-1].id) << endl;
}

