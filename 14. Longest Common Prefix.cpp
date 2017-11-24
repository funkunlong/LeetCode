#include<iostream>
#include<vector>
using namespace std;
//先用最烂的方法做一下
//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		string s = "";
//		if (strs.size() == 0)return s;
//		s = strs[0];
//		for(int i=1;i<strs.size();i++)
//			for (int j = 0; j < s.size(); j++)
//			{
//				if (s[j] != strs[i][j])
//				{
//					s = s.substr(0, j);
//					break;
//				}
//			}
//		return s;
//	}
//};

//sample 3ms submission
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
		{
			return "";
		}

		string prefix = strs[0];
		for (int i = 1; i < strs.size(); i++)
		{
			while (0 != strs[i].compare(0, prefix.length(), prefix))
			{
				prefix = prefix.substr(0, prefix.length() - 1);
			}
		}

		return prefix;
	}
};