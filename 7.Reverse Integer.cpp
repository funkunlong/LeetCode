//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int reverse(int x) {
//		int ans = 0,flag=1;
//		if (x < 0) {
//			flag = -1;
//			x = -x;
//		}
//		vector<int>vec;
//		while (x) {
//			vec.push_back(x % 10);
//			x /= 10;
//		}
//		int len = vec.size();
//		int i = 0;
//		while (vec[i] == 0)i++;
//		for (; i < len; i++) {
//				ans = ans * 10 + vec[i];
//		}
//		ans *= flag;
//		return ans;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.reverse(123) << endl;
//	return 0;
//}


//以上这个代码当输入是1534236469时无法通过，我的输出是1056389759，而expected是0
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int reverse(int x) {
//		int ans = 0,flag=1;
//		if (x < 0) {
//			flag = -1;
//			x = -x;
//		}
//		vector<int>vec,VEC;
//		while (x) {
//			vec.push_back(x % 10);
//			x /= 10;
//		}
//		int len = vec.size();
//		int i = 0;
//		while (vec[i] == 0)i++;
//		for (; i < len; i++) {
//				ans = ans * 10 + vec[i];
//				VEC.push_back(vec[i]);
//		}
//		if (VEC.size() == 10)
//		{
//			if (VEC[0] != vec[9])
//				return 0;
//		}
//		ans *= flag;
//		return ans;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.reverse(4294967296) << endl;
//	return 0;
//}


//以上代码依然是不可行的，会越vector的界

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//#define int_num (-2147483647-1)
//
//class Solution {
//public:
//	int reverse(int x) {
//		string s = to_string(x);
//		if (s[0] == '-')
//			std::reverse(s.begin() + 1, s.end());
//		else
//			std::reverse(s.begin(), s.end());
//		long long int temp = stoll(s);
//		if (temp > 2147483647 || temp < int_num)
//			return 0;
//		return (int)temp;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.reverse(1563847412) << endl;
//	return 0;
//}


//以上代码虽然可以通过，但是不够优秀
class Solution {
public:
	int reverse(int x) {
		int flag = (x < 0) ? -1: 1;
		long long res = 0;
		x = abs(x);
		while (x != 0) {
			res = 10 * res + x % 10;
			x /= 10;
		}
		res *= flag;
		return (res > 2147483647 || res < -2147483648) ? 0 : res;
	}
};