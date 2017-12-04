#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		//写到一半感觉有点写不下去了
		//string temp="";
		//vector<string>result;
		//int len = digits.size();
		//string s[] = { "", "abc","def","ghf","jkl","mno","pqrs","tuv","wxyz"};
		//for (int i = 0; i < len; i++)
		//{
		//	if (isdigit(digits[i]))
		//	{
		//		digits = digits.substr(i);
		//		len -= i;
		//		break;
		//	}
		//}
		//for (int i = 0; i < len - 1; i++) {
		//	temp.push_back()
		//}
		//以下是从网上看的解法
		vector<string>result;
		if (digits.length() == 0)return result;
		result.push_back("");
		vector<string>v= { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (int i = 0; i < digits.size(); i++) {
			string s = v[digits[i] - '0'];
			vector<string>temp;
			//for (int j = 0; j < s.size(); j++)
			//	for (int k = 0; k < result.size(); k++)
			//		temp.push_back(result[k] + s[j]);
			for (int k = 0; k < result.size(); k++)
			    for (int j = 0; j < s.size(); j++)
				   temp.push_back(result[k] + s[j]);
			result = temp;
		}
		return result;
	}
};

//以下为使用深度优先搜索的方法
class dfs_solution{
	vector<string> letterCombinations(string digits) {
		if (digits == "")
			return {};

		vector<string>d_map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string>res;
		dfs(digits, 0, "", res, d_map);
		return res;
	}
	void dfs(string digits, int pos, string letters, vector<string>&res, 
		vector<string>&d_map) {
		if (pos == digits.size()) {
			res.push_back(letters);
			return;
		}

		for (char c : d_map[digits[pos] - '0'])
			dfs(digits, pos + 1, letters + c, res, d_map);
	}
};