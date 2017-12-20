#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>ans = { -1,-1 };
		if (nums.empty() || nums[0]>target || *(--nums.end())<target)return ans;
		if (nums.size() == 1) {
			if (target == nums[0])
			{
				ans[0] = 0; ans[1] = 0;

			}
			return ans;
		}
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi) {
			int middle = (lo + hi) / 2;
			if (nums[middle] == target) {
				int n1, n2;
				for (n1 = middle; n1 <= hi; n1++) {
					if (nums[n1] != target)break;
				}
				for (n2 = middle; n2 >= lo; n2--) {
					if (nums[n2] != target)break;
				}
				ans[0]=(n2 + 1); ans[1]=(n1 - 1);
				break;
			}
			if (nums[middle] < target) {
				lo = middle + 1;
			}
			else {
				hi = middle - 1;
			}
		}
		return ans;
	}
};