#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	vector<string>result;
	vector<string> generateParenthesis(int n) {
		//可以用递归实现所有的组合
		int left = n, right = n;
		string s = "";
		generateleft(s,left-1, right);
		generateright(s, left, right-1);
		return result;
	}
	void generateleft(string s, int left, int right) {
		s = s + "(";
		if (left == 0 && right == 0) {
			if (isValid(s))
			result.push_back(s);
			return;
		}
		else if (left == 0 && right > 0) {
			generateright(s, left, right-1);
		}
		else if (left > 0 && right == 0) {
			generateleft(s, left-1, right);
		}
		else {
			generateright(s, left, right - 1);
			generateleft(s, left - 1, right);
		}
	}
	void generateright(string s, int left, int right) {
		s = s + ")";
		if (left == 0 && right == 0) {
			if (isValid(s))
				result.push_back(s);
			return;
		}
		else if (left == 0 && right > 0) {
			generateright(s, left, right - 1);
		}
		else if (left > 0 && right == 0) {
			generateleft(s, left - 1, right);
		}
		else {
			generateright(s, left, right - 1);
			generateleft(s, left - 1, right);
		}
	}
	bool isValid(string s) {
		stack<char>ans;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(')
				ans.push(s[i]);
			else
			{
				if (ans.empty())return false;
				else if (ans.top() == '('&&s[i] == ')')
					ans.pop();
				else return false;
			}
		}
		if (ans.empty())return true;
		else return false;
	}
};