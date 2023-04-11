// Longest Substring Without Repeating Characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<map>
using namespace std;
int lengthOfLongestSubstring(string s)
{
	map<char, int>hash_table;
	if (s.size() < 2) return s.size();
	int subtring_size = 0;
	int temp = 0;
	int start = 0;
	for (int curr = 0;curr < s.size();curr++)
	{
		if (hash_table.count(s[curr]))
		{
			if (hash_table[s[curr]] >= start)
			{
				temp = (curr - hash_table[s[curr]]);
				start = hash_table[s[curr]] + 1;				
			}
			else temp++;
			hash_table[s[curr]] = curr;
		}
		else
		{
			pair<char, int>keys;
			keys.first = s[curr];
			keys.second = curr;
			hash_table.insert(keys);
			temp++;
		}
		if (temp > subtring_size)
			subtring_size = temp;
	}
	return subtring_size;
}
int main()
{
	string s = "aabaab!bb";
	cout << lengthOfLongestSubstring(s);
	
}

