#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if ((haystack.empty() && needle.empty())|| (!haystack.empty() && needle.empty()))
			return 0;
		if (haystack.empty() && !needle.empty())
			return -1;
		for (int i = 0; i < haystack.size(); i++) {
			if (haystack[i] == needle[0]) {
				int j = 0;
				while ((j + i) < haystack.size() && j < needle.size()) {
					if (haystack[i + j] != needle[j])
						break;
					j++;
				}
				if (j == needle.size())
				{
					return i;
				}
			}
		}
		return -1;
	}
};