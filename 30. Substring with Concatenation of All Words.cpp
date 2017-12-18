#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;

//我是否可以考虑生成所有的可能的组合
//class Solution {
//public:
//	vector<string>words_combinations;
//	vector<int> findSubstring(string s, vector<string>& words) {
//		vector<int>result;
//		int len = words.size();
//		vector<bool>hashTable;
//		string temp_s = "";
//		for (int i = 0; i < len; i++) {
//			hashTable.push_back(false);//false代表未使用
//		}
//		generate_words_combinations(words, 0, temp_s, hashTable);
//		//for (int i = 0; i < words_combinations.size(); i++)
//		//{
//		//	cout << words_combinations[i] << endl;
//		//}
//		for (int i = 0; i < words_combinations.size(); i++) {
//			int num = 0, pos = 0;
//			string sub_s = words_combinations[i];
//			string copy_s = s;
//			while ((pos = copy_s.find(sub_s)) || pos == 0) {
//				if (pos == -1)break;
//				//cout << "ceshi pos:"<<pos << endl;
//				//system("pause");
//				//cout << copy_s << endl;
//				string copy_s1 = "", copy_s2 = "";
//				if (pos >= 1)
//				{
//					copy_s1 = copy_s.substr(0, pos);
//				}
//				copy_s2 = copy_s.substr(pos + 1);
//				copy_s = copy_s1 + copy_s2;
//				//cout << sub_s << endl;
//				//cout << copy_s << endl;
//				result.push_back(pos + num);
//				num += 1;
//			}
//		}
//		sort(result.begin(), result.end());
//		return result;
//	}
//	void generate_words_combinations(vector<string>&words, int index, string tmp_s, vector<bool>hashTable) {
//		if (index == words.size()) {
//			words_combinations.push_back(tmp_s);
//			return;
//		}
//		for (int i = 0; i < words.size(); i++) {
//			string s = tmp_s;
//			if (hashTable[i] == false) {
//				hashTable[i] = true;
//				s += words[i];
//				generate_words_combinations(words, index + 1, s, hashTable);
//				hashTable[i] = false;
//			}
//		}
//	}
//};


//class Solution {
//public:
//	set<string>words_combinations;
//	vector<int> findSubstring(string s, vector<string>& words) {
//		vector<int>result;
//		int len = words.size();
//		vector<bool>hashTable;
//		string temp_s = "";
//		for (int i = 0; i < len; i++) {
//			hashTable.push_back(false);//false代表未使用
//		}
//		generate_words_combinations(words, 0, temp_s, hashTable);
//
//		//for (auto it=words_combinations.begin(); it!= words_combinations.end(); it++)
//		//{
//		//	cout << *it << endl;
//		//}
//		for (set<string>::iterator it = words_combinations.begin(); it != words_combinations.end(); it++) {
//			int num = 0, pos = 0;
//			string sub_s = *it;
//			string copy_s = s;
//			while ((pos = copy_s.find(sub_s)) || pos == 0) {
//				if (pos == -1)break;
//				//cout << "ceshi pos:"<<pos << endl;
//				//system("pause");
//				//cout << copy_s << endl;
//				string copy_s1 = "", copy_s2 = "";
//				if (pos >= 1)
//				{
//					copy_s1 = copy_s.substr(0, pos);
//				}
//				copy_s2 = copy_s.substr(pos + 1);
//				copy_s = copy_s1 + copy_s2;
//				//cout << sub_s << endl;
//				//cout << copy_s << endl;
//				result.push_back(pos + num);
//				num += 1;
//			}
//		}
//		sort(result.begin(), result.end());
//		return result;
//	}
//	void generate_words_combinations(vector<string>&words, int index, string tmp_s, vector<bool>hashTable) {
//		if (index == words.size()) {
//			words_combinations.insert(tmp_s);
//			return;
//		}
//		for (int i = 0; i < words.size(); i++) {
//			string s = tmp_s;
//			if (hashTable[i] == false) {
//				hashTable[i] = true;
//				s += words[i];
//				generate_words_combinations(words, index + 1, s, hashTable);
//				hashTable[i] = false;
//			}
//		}
//	}
//};

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>&words)
	{
		vector<int>result;
		int len = words[0].length(), num = words.size(), n = s.length();
		unordered_map<string, int>counts;
		for (int i = 0; i < num; i++) {
			counts[words[i]]++;
		}
		for (int i = 0; i < n - num*len + 1; i++) {
			unordered_map<string, int>tmp_counts;
			int j = 0;
			for (; j < num; j++)
			{
				string tmp_s = s.substr(i + j*len, len);
				if (counts.find(tmp_s) != counts.end())
				{
					tmp_counts[tmp_s]++;
				}
				else break;
				if (tmp_counts[tmp_s] > counts[tmp_s])
					break;
			}
			if (j == num)
				result.push_back(i);
		}
		return result;
	}
};


