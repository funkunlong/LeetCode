#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0)return 0;
		int i = 0, flag = 1,j=0;
		//���汻ע�͵��Ĵ���������⣬��Ϊ������+-2ʱ,expected answer��0,������-2
		//for (; i < str.length(); i++) {
		//	if (isdigit(str[i]))
		//		break;
		//}
		//i--;
		//if (str[i] == '-')
		//	flag = 0;
		//i++;

		//���汻ע�͵��Ĵ�����Ȼ�����⣬��������"   - 321"��Output:321����Expected:0
		//for (; i < str.length(); i++) {
		//	if (isdigit(str[i]))
		//		break;
		//}
		//i--;
		//if (i != 0)
		//{
		//	if ((str[i] == '+'&&str[i - 1] == '-')||(str[i] == '-'&&str[i - 1] == '+'))
		//		return 0;
		//}
		//if (str[i] == '-')
		//	flag = 0;
		//i++;

		str = str.substr(i);
		while (isdigit(str[j]))
			j++;
		str = str.substr(0, j);
		if (str.size() == 0)return 0;
		if (str.length() > 10) {
			if (flag == 0)
				return -2147483648;
			else
				return 2147483647;
		}
		long long int ans = stoll(str);
		if (flag == 0)
			ans = -ans;
		if (ans > 2147483647)
		{
			return 2147483647;
		}
		else if (ans < -2147483648) {
			return -2147483648;
		}
		else {
			return (int)ans;
		}
	}
};