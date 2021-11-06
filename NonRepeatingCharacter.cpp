#include<iostream>
#include<unordered_map>
using namespace std;
//Brute Force O(N^2)
char findFirstNonRepeatingCharacter(const string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		int j;
		for (j = 0; j < str.length(); j++)
		{
			if (str[i] == str[j] && i != j)
				break;
		}
		if (j == str.length())
		{
			return str[i];
		}
	}
}
//O(N) when N is string size using Array
//This solution only works for lowercase alphabet characters
char findFirstNonRepeatingCharacter1(const string & str)
{
	int charArray[26] = { 0 };
	for (int i = 0; i < str.length(); i++)
	{
		charArray[str[i] - 'a']++;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (charArray[i] == 1)
		{
			return(char)(i + 'a');
		}
	}
}
//O(N) solution when N is string size using HashMap
char findFirstNonRepeatingCharacter2(const string& str)
{
	unordered_map<char, int> maps;
	for (int i = 0; i < str.length(); i++)
	{
		unordered_map<char, int>::iterator it;
		it = maps.find(str[i]);
		if (it == maps.end())
		{
			maps.insert(pair<char, int>(str[i], 1));
		}
		else
		{
			maps[str[i]]++;
		}
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (maps[str[i]] == 1)
		{
			return str[i];
		}
	}
}
int main()
{
	  string str = "aaabcbcdefeef";
	//string str = "AAABCBCDEFEEF";
	//string str = "AABBF+EF";
	//string str = "AAABCBCDEFDEFE&";
	cout << "First Non Repeating Character: " << findFirstNonRepeatingCharacter(str) << endl;
	cout << "First Non Repeating Character: " << findFirstNonRepeatingCharacter1(str) << endl;
	cout << "First Non Repeating Character: " << findFirstNonRepeatingCharacter2(str) << endl;
	return 0;
}