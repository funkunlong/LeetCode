//�����Ŀ�϶�Ҳ��������
//����һ���Ƚ�����������������ÿһ��λ�ö������ж�
#include<iostream>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0)return "";
		string result = s.substr(0, 1);
		for (int i = 0; i <=len-2; i++)
		{
			string temp = midToSide(s, i, i);
			if (temp.length() > result.size())
				result = temp;
			temp = midToSide(s, i, i + 1);
			if (temp.length() > result.size())
				result = temp;
		}
		return result;
	}
	string midToSide(string s, int left, int right) {
		while (left >= 0 && right <= s.length() - 1) {
			if (s[left] != s[right])break;
			left--; right++;
		}
		return s.substr(left+1,right-left-1);
	}
};