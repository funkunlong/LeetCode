#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//问题依然是如何确定选数策略，可以使得最后所有的组合都被选到
class my_59ms_Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<int>temp(4);
		vector<vector<int>>result;
		int len = nums.size();
		if (len < 4)return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len; i++) {
			if (i>0 && nums[i] == nums[i - 1])continue;
			for (int j = i + 1; j < len; j++) {
				if (j>(i+1)&&nums[j] == nums[j - 1])continue;
				int begin = j + 1;
				int end = len - 1;
				while (begin < end) {
					temp[0] = nums[i]; temp[1] = nums[j];
					temp[2] = nums[begin]; temp[3] = nums[end];
					int sum = temp[0] + temp[1] + temp[2] + temp[3];
					if (sum == target) {
						result.push_back(temp); begin++; end--;
						while (begin < end&&nums[begin - 1] == nums[begin])begin++; 
						while (begin < end&&nums[end+1] == nums[end])end--;
					}
					else {
						if (sum < target) {
							begin++;
						}
						else {
							end--;
						}
					}
				}
			}
		}
		return result;
	}
};

//其实下面这个算法思路上没什么难的，就是充分的剪枝而已
class sample_9ms_Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>>total;
		int n = nums.size();
		if (n < 4)return total;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; i++) {
			if (i>0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]>target) break;
			if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1]<target) continue;
			for (int j = i + 1; j < n - 2; j++) {
				if (j>i + 1 && nums[j] == nums[j - 1]) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2]>target) break;
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1]<target) continue;
				int left = j + 1, right = n - 1;
				while (left < right) {
					int sum = nums[left] + nums[right] + nums[i] + nums[j];
					if (sum<target) left++;
					else if (sum>target) right--;
					else {
						total.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						do { left++; } while (nums[left] == nums[left - 1] && left<right);
						do { right--; } while (nums[right] == nums[right + 1] && left<right);
					}
				}
			}
		}
	}
};