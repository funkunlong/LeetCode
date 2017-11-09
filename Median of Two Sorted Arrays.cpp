//这个题目之前在刷408的时候见到过
//但是做这个题目还是没有头绪
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& num1, vector<int>&num2) {
		int m = num1.size(), n = num2.size();
		return (findKth(num1, num2, (m + n + 1) / 2) + findKth(num1, num2, (m + n + 2) / 2)) / 2.0;
	}
	int findKth(vector<int>num1, vector<int>num2, int k) {
		int m = num1.size(), n = num2.size();
		if (m > n)return findKth(num2, num1, k);
		if (m == 0)return num2[k - 1];
		if (k == 1)return min(num1[0], num2[0]);
	}
};
int main() {
	return 0;
}

