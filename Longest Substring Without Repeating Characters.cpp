#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxn = -1,len=s.size();
		int a[256] = { 0 }; int i=0, j=0;
		//for (i = 0; i < len; i++)
		//{
		//	for (; j < len; j++) {
		//		if (a[s[j]] == 0)
		//		{
		//			a[s[j]] = 1;
		//			
		//		}
		//		else {
		//			maxn = max(maxn, j - i);
		//			while (s[i] != s[j])
		//			{
		//				a[s[i]] = 0;
		//				i++;
		//			}
		//			i--;
		//			j++;
		//			break;
		//		}
		//	}
		//}
		while (j < len) {
			if (a[s[j]] == 0) {
				a[s[j]] = 1;
			}
			else {
				maxn = max(maxn, j - i);
				while (s[i] != s[j])
				{
					a[s[i]] = 0;
					i++;
				}
				i++;
			}
			j++;
		}
		maxn = max(maxn, j - i);
		return maxn;
	}
};

int main()
{
	string s;
	cin >> s;
	Solution ans;
	
	cout << ans.lengthOfLongestSubstring(s) << endl;
	return 0;
}