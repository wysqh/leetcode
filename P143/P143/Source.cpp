#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//    void reorderList(ListNode* head) {
//        map<int, ListNode*> maps;
//        ListNode* ptr = head;
//        int indice = -1;
//        while (ptr != nullptr){
//            maps[++indice] = ptr;
//            ptr = ptr->next;
//        }
//
//        for (int i = 0; i < indice / 2; ++i){
//            maps[i]->next = maps[indice-i];
//            maps[indice-i]->next = maps[i+1];
//        }
//
//        if (indice%2 != 0){
//            maps[indice/2]->next = maps[indice/2+1];
//			maps[indice/2+1]->next = nullptr;
//		}else{
//			maps[indice/2]->next = nullptr;
//		}
//    }
//};
//
//int main()
//{
//	cout << atoi("+") << endl;
//	ListNode* head = new ListNode(1);
//	ListNode* h1 = new ListNode(2);
//	ListNode* h2 = new ListNode(3);
//	head->next = h1;
//	h1->next = h2;
//
//	char a;
//	switch (a)
//	{
//	default:
//		break;
//	}
//
//	Solution s;
//	s.reorderList(head);
//	while (head != nullptr)
//	{
//		cout << head->val << " ";
//		head = head->next;
//	}
//}
