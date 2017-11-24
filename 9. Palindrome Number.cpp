//这个题是做过的最容易的
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		bool flag = true;
		stringstream ss;
		ss << x;
		string s = ss.str();
		int len = s.length(), middle = len / 2;
		if (len % 2 == 1) {
			for (int j = middle, k = middle; j >= 0 && k < len; j--, k++)
			{
				if (s[j] != s[k]) {
					flag = false;
					break;
				}
			}
		}
		else {
			for (int j = middle-1, k = middle; j >= 0 && k < len; j--, k++)
			{
				if (s[j] != s[k]) {
					flag = false; break;
				}
			}
		}
		return flag;
	}
};