#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//以下是第一次尝试的方法，有测试用例过不了
//class Solution {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		vector<vector<int>>ans;
//		vector<int>vec;
//		int len = nums.size();
//		for(int i=0;i<len;i++)
//			for(int j=i+1;j<len;j++)
//				for (int k = j + 1; k < len; k++)
//				{
//					if (nums[i] + nums[j] + nums[k] == 0)
//					{
//						vec.clear();
//						vec.push_back(nums[i]);
//						vec.push_back(nums[j]);
//						vec.push_back(nums[k]);
//						ans.push_back(vec);
//					}
//				}
//		return ans;
//	}
//};


//这个无法解决重复的问题
//class Solution {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		vector<vector<int>>ans;
//		vector<int>vec;
//		int len = nums.size();
//		for (int i = 0; i<len; i++)
//			for (int j = i + 1; j<len; j++)
//				for (int k = j + 1; k < len; k++)
//				{
//					if (nums[i] + nums[j] + nums[k] == 0)
//					{
//						vec.clear();
//						vec.push_back(nums[i]);
//						vec.push_back(nums[j]);
//						vec.push_back(nums[k]);
//						ans.push_back(vec);
//					}
//				}
//		return ans;
//	}
//};


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//这三个数的组合策略很有讲究，每次有一个i，一个begin,一个end，这样最终也是可以保证所有的都组合一遍
		//为了防止重复，我们在nums[i]==nums[i-1]时continue
		//通过对数组进行排序，我们可以有更优的选择策略
		vector<vector<int>>ans;
		if (nums.size() <3)return ans;
		int len = nums.size();
		vector<int>temp(3);//这样到时候直接赋值可以省时间
		sort(nums.begin(), nums.end());//从小到大排列
		if (nums[0] > 0)return ans;
		for (int i = 0; i < len; i++) {
			if (i > 0 && nums[i] == nums[i - 1])continue;
			int begin = i + 1, end = len - 1;
			while (begin < end) {
				temp[0] = nums[i];
				temp[1] = nums[begin];
				temp[2] = nums[end];
				if (temp[0] + temp[1] + temp[2] == 0) {
					ans.push_back(temp); begin++, end--;
					while (begin < end && nums[begin] == nums[begin - 1]) begin++;
					while (begin < end && nums[end] == nums[end + 1]) end--;
				}
				else {
					if (temp[0] + temp[1] + temp[2] < 0)
						begin++;
					else
						end--;
				}
			}
		}
		return ans;
	}
};