#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//����ж������������������ף�ֻҪÿһ����λ�����ڵ��ڵ�λ����
		//���Ǵ����ʼ�����жϣ������λС�ڵ�λ��һ��λ�ü��ɣ����һֱ������ѭ����û������������֣��ʹ�ͷ��βȫ����ת����
		//�������ϲ����ǲ��еģ����翼��[1,3,2]
		//��ʵ�ϣ�����������ҵ���һ����Ҫ�滻��λ�ã�Ȼ������滻��֮������滻λ��֮�������sortһ�¼���
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