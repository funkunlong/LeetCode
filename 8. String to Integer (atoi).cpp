#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0)return 0;
		int i = 0, flag = 1,j=0;
		//下面被注释掉的代码很有问题，因为当输入+-2时,expected answer是0,而我是-2
		//for (; i < str.length(); i++) {
		//	if (isdigit(str[i]))
		//		break;
		//}
		//i--;
		//if (str[i] == '-')
		//	flag = 0;
		//i++;

		//下面被注释掉的代码仍然有问题，比如输入"   - 321"，Output:321，而Expected:0
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