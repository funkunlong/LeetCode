#include<iostream>
#include<vector>
using namespace std;

//使用二分法吧
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		int middle;
		while (lo <= hi)
		{
			middle = (lo + hi) / 2;
			if (nums[middle] == target) {
				return middle;
			}
			if (nums[middle] < target)
			{
				lo = middle + 1;
			}
			else {
				hi = middle - 1;
			}
		}
		if (nums[middle] < target)
			return middle + 1;
		else
			return middle;
	}
};