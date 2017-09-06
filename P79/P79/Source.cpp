#include <vector>
#include <string>
#include <sstream>

//10%

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		bool bFind = false;
		if (board.size() == 0)
			return bFind;

		vector<vector<int>> record(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
			{
				stringstream ss;
				string cmpWord = "";
				ss << board[i][j];
				ss >> cmpWord;
				search(board, cmpWord, word, 1, word.size(), i, j, bFind, record);
			}

			return bFind;
    }

	void search(vector<vector<char>> board, string cmpWord, string word, int length, int n, int i, int j, bool &bFind, vector<vector<int>> record)
	{
	    record[i][j] = 1;
		if (cmpWord != word.substr(0, length))
		{
			record[i][j] = 0;
			return;
		}

		if (length == n)
		{
			bFind = true;
			return;
		}

		if ( i - 1 >= 0 && !bFind && record[i-1][j] == 0)
		{
			search(board, cmpWord + board[i-1][j], word, length + 1, n, i - 1, j, bFind, record);
			record[i-1][j] = 0;
		}
		if ( i + 1 < board.size() && !bFind && record[i+1][j] == 0)
		{
			search(board, cmpWord + board[i+1][j], word, length + 1, n, i + 1, j, bFind, record);
			record[i+1][j] = 0;
		}
		if (j - 1 >= 0 && !bFind && record[i][j-1] == 0)
		{
			search(board, cmpWord + board[i][j-1], word, length + 1, n, i, j - 1, bFind, record);
			record[i][j-1] = 0;
		}
		if ( j + 1 < board[0].size() && !bFind && record[i][j+1] == 0)
		{
			search(board, cmpWord + board[i][j+1], word, length + 1, n, i, j + 1, bFind, record);
			record[i][j+1] = 0;
		}

		return;
	}
};