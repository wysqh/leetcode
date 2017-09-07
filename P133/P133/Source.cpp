#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

 struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    unordered_map<int, UndirectedGraphNode *> copy;
    void bfs(UndirectedGraphNode *node) {
        if(copy.find(node->label) != copy.end()) return;
        UndirectedGraphNode * tmp = new UndirectedGraphNode(node->label);
        copy[node->label] = tmp;
        for(auto val : node->neighbors) {
            if(copy.find(val->label) == copy.end())
                bfs(val);
            tmp->neighbors.push_back(copy[val->label]);
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        bfs(node);
        return copy[node->label];
    }

};