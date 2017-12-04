#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char>ans;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == '[' || s[i] == '(' || s[i] == '{')
				ans.push(s[i]);
			else
			{
				if (ans.empty())return false;
				else if ((ans.top() == '('&&s[i] == ')') || (ans.top() == '['&&s[i] == ']') || (ans.top() == '{'&&s[i] == '}') )
					ans.pop();
				else return false;
			}
		}
		if (ans.empty())return true;
		else return false;
	}
};