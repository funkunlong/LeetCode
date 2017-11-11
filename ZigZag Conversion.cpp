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

//��һ�к����һ���±�������interval = n*2-2 = 8 
//�м��еĹ���û���Ҷԣ��м��еļ���������Եģ���i�еļ����:interval-2*i,2*i,interval-2*i
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)return s;
		int len = s.size(), k = 0, interval = (numRows << 1) - 2;
		string res(len, ' ');
		for (int j = 0; j < len; j += interval)
			res[k++] = s[j];
		for (int i = 1; i < numRows - 1; i++)
		{
			int inter = (i << 1);
			for (int j = i; j < len; j += inter)
			{
				res[k++] = s[j];
				inter = interval - inter;//����дȷʵ��Ư��
			}
		}
		for (int j = numRows - 1; j < len; j += interval)
			res[k++] = s[j];
		return res;
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