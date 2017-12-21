#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int len = board.size();
		for (int i = 0; i < len; i++)
		{
			bool table1[10] = { false };
			bool table2[10] = { false };
			for (int j = 0; j < len; j++)
			{
				if (board[i][j] != '.') {
					if (table1[board[i][j] - '0'])
						return false;
					table1[board[i][j] - '0'] = true;
				}
				if (board[j][i] != '.') {
					if (table2[board[j][i] - '0'])
						return false;
					table2[board[j][i] - '0'] = true;
				}
			}
		}
		for(int i=0;i<= len-3;i+=3)
			for (int j = 0; j <= len-3; j += 3)
			{
				bool table[10] = { false };
				for(int k=i;k<i+3;k++)
					for (int l = j; l < j + 3; l++) 
					{
						if (board[k][l] == '.')continue;
						if (table[board[k][l] - '0'])
							return false;
						table[board[k][l] - '0'] = true;
					}
			}
		return true;
	}
};