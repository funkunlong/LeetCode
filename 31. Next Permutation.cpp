#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//如何判断已是最大的数，很容易，只要每一个高位都大于等于低位即可
		//我们从最后开始倒着判断，如果高位小于低位换一下位置即可，如果一直到跳出循环都没有这种情况出现，就从头到尾全部反转即可
		//但是以上策略是不行的，比如考虑[1,3,2]
		//事实上，这个策略是找到第一个需要替换的位置，然后进行替换，之后将这个替换位置之后的所有sort一下即可
		bool flag = true;
		int len = nums.size();
		for (int i = len - 2; i >= 0; i--) {
			for (int j = len - 1; j > i; j--) {
				if (nums[i] < nums[j])
				{
					flag = false;
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
					break;
				}
			}
			if (!flag) {
				sort(nums.begin() + i + 1, nums.end());
				break;
			}
		}
		if (flag) {
			int temp;
			for (int i = 0; i < len / 2 + 1; i++) {
				temp = nums[i];
				nums[i] = nums[len - 1 - i];
				nums[len - 1 - i] = temp;
			}
		}
	}
};