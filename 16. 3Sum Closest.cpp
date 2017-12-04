#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//依然是要找出所有三个数的和
		int len = nums.size();
		vector<int>temp(3);
		int ans = 99999999,temp_num=0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len; i++) {
			int begin = i + 1, end = len - 1;
			while (begin < end) {
				temp[0] = nums[i];
				temp[1] = nums[begin];
				temp[2] = nums[end];
				temp_num = temp[0] + temp[1] + temp[2];
				if (temp_num == target)return target;
				if (abs(temp_num - target) < abs(ans - target)) {
					ans = temp_num;
				}
				if (temp_num < target) {
					
					begin++;
				}
				else {
					end--;
				}
			}
		
		}
		return ans;
	}
};