#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())return 0;
		int len = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
				nums[len++] = nums[i];
		}
		return len;
	}
};