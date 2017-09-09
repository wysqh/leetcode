#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class TrieNode
{
public: 
	bool isKey;	//whether the string comprised of characters starting from root to the current node.
	TrieNode* children[26];
	TrieNode() : isKey(false)
	{
		memset(children, NULL, sizeof(TrieNode*) * 26);
	}

};

class WordDictionary {
public:
	TrieNode* root;
    WordDictionary() {
		root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
		TrieNode* run = root;
		for (const char&c : word)
		{
			if (!(run->children[c-'a']))
				run->children[c-'a'] = new TrieNode();
			run = run->children[c-'a'];
		}
		run->isKey = true;
    }

    bool search(string word) {
		return search(word, 0, root);
    }

	bool search(const string &word, int pos, TrieNode *root) {
		if (pos == word.size()) return root->isKey;
        if (word[pos] != '.') {
			root = root->children[word[pos]-'a'];
            return root ? search(word, pos + 1, root) : false;
        }
        for (auto i = 0; i < 26; ++i)
			if (root->children[i] && search(word, pos + 1, root->children[i]))
                return true;

		return false;
    }
};

/*
 A TLE Solution
*/
//public class WordDictionary {
//    public class TrieNode {
//        public TrieNode[] children = new TrieNode[26];
//        public String item = "";
//    }
//    
//    private TrieNode root = new TrieNode();
//
//    public void addWord(String word) {
//        TrieNode node = root;
//        for (char c : word.toCharArray()) {
//            if (node.children[c - 'a'] == null) {
//                node.children[c - 'a'] = new TrieNode();
//            }
//            node = node.children[c - 'a'];
//        }
//        node.item = word;
//    }
//
//    public boolean search(String word) {
//        return match(word.toCharArray(), 0, root);
//    }
//    
//    private boolean match(char[] chs, int k, TrieNode node) {
//        if (k == chs.length) return !node.item.equals("");   
//        if (chs[k] != '.') {
//            return node.children[chs[k] - 'a'] != null && match(chs, k + 1, node.children[chs[k] - 'a']);
//        } else {
//            for (int i = 0; i < node.children.length; i++) {
//                if (node.children[i] != null) {
//                    if (match(chs, k + 1, node.children[i])) {
//                        return true;
//                    }
//                }
//            }
//        }
//        return false;
//    }
//}