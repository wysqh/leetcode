#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

//learning£¡
class map_finder
{
public:
    map_finder(const RandomListNode* _node):node(_node){}
	bool operator ()(const std::map<int, RandomListNode*>::value_type &pair)
    {
        return pair.second == node;
		size_t
	}
private:
        const RandomListNode* node;                   
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<int, RandomListNode*> maps;
        map<int, RandomListNode*> newMaps;
        RandomListNode* ptr = head;
        int index = 0;
        while (ptr != nullptr) {
            maps[index++] = ptr;
            ptr = ptr->next;
        }
        
        ptr = head;
        index = 0;
        while (ptr != nullptr) {
            RandomListNode* node = new RandomListNode(ptr->label);
            newMaps[index++] = node;
            ptr = ptr->next;
        }
        
        for(map<int, RandomListNode*>::iterator it = newMaps.begin(); it != newMaps.end(); it++) {
            map<int, RandomListNode*>::iterator latIt = it;
            latIt ++;
            if (latIt == newMaps.end())
                continue;
            
			(*it).second->next = (*latIt).second;
        }
        
        for (map<int, RandomListNode*>::iterator it = maps.begin(), it2 = newMaps.begin(); it != maps.end(); it++, it2++) {
			map<int, RandomListNode*>::iterator iter = find_if(maps.begin(), maps.end(), map_finder((*it).second->random));
            if (iter != maps.end()){
                (*it2).second->random = (*newMaps.find((*iter).first)).second;
            }
        }
        
        return newMaps.empty() ? nullptr : (*newMaps.find(0)).second;
    }
};

int main()
{
	Solution s;
	s.copyRandomList(nullptr);
}