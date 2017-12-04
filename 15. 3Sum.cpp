#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�����ǵ�һ�γ��Եķ������в�������������
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


//����޷�����ظ�������
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
		//������������ϲ��Ժ��н�����ÿ����һ��i��һ��begin,һ��end����������Ҳ�ǿ��Ա�֤���еĶ����һ��
		//Ϊ�˷�ֹ�ظ���������nums[i]==nums[i-1]ʱcontinue
		//ͨ������������������ǿ����и��ŵ�ѡ�����
		vector<vector<int>>ans;
		if (nums.size() <3)return ans;
		int len = nums.size();
		vector<int>temp(3);//������ʱ��ֱ�Ӹ�ֵ����ʡʱ��
		sort(nums.begin(), nums.end());//��С��������
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