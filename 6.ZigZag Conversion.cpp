//#include<iostream>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		int len = s.size();
//		for (int i = 0; i < len; i += 2 * numRows - 2)
//			printf("%c", s[i]);
//
//		for (int i = 1; i < numRows-1; i++)
//		{
//			for (int j = i; j < len; j+= 2*numRows-2)
//			{
//				printf("%c", s[j]);
//				int n = j + 2 * numRows - 2 * i - 2;
//				if (n < len)
//					printf("%c", s[n]);
//			}
//		}
//		for (int i = numRows-1; i < len; i += 2*numRows - 2)
//		{
//			printf("%c", s[i]);
//		}
//	}
//};
//int main()
//{
//	string s;
//	cin >> s;
//	Solution c;
//	c.convert(s,3);
//	return 0;
//}

//第一行和最后一行下标间隔都是interval = n*2-2 = 8 
//中间行的规律没有找对，中间行的间隔是周期性的，第i行的间隔是:interval-2*i,2*i,interval-2*i
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string new_s;
		int len = s.size();
		for (int i = 0; i < len; i += 2 * numRows - 2)
			//printf("%c", s[i]);
			new_s.push_back(s[i]);


		for (int i = 1; i < numRows - 1; i++)
		{
			for (int j = i; j < len; j += 2 * numRows - 2)
			{
				//printf("%c", s[j]);
				new_s.push_back(s[j]);
				int n = j + 2 * numRows - 2 * i - 2;
				if (n < len)
					//printf("%c", s[n]);
					new_s.push_back(s[n]);
			}
		}
		for (int i = numRows - 1; i < len; i += 2 * numRows - 2)
		{
			//printf("%c", s[i]);
			new_s.push_back(s[i]);
		}
		return new_s;
	}
};
int main()
{
	string s;
	cin >> s;
	Solution c;
	c.convert(s,3);
	return 0;
}