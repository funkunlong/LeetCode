#include<iostream>
#include<vector>
using namespace std;

//int search(vector<int>&nums, int target) {
//	int lo = 0, hi = nums.size();
//	while (lo < hi) {
//		int mid = (lo + hi) / 2;
//		double num = (nums[mid] < nums[0]) == (target < nums[0])
//			? nums[mid]
//			: target < nums[0] ? -INFINITY : INFINITY;
//		if (num < target)
//			lo = mid + 1;
//		else if (num > target)
//			hi = mid;
//		else
//			return mid;
//	}
//	return -1;
//}


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())return -1;
		int lo = 0;
		int hi = nums.size() - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] == target)return mid;

			if (nums[lo] <= nums[mid]) {//说明前半部分一定是有序的，所以下面的判断条件是那样的
				if (target >= nums[lo] && target < nums[mid]) {
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
			else {
				if (target > nums[mid] && target <= nums[hi]) {
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}
		}
		return target == nums[lo] ? lo : -1;
	}
	
};