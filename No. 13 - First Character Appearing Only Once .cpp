#include <iostream>
#include <vector>
#include <map>
using namespace std;


bool findOnce(const string& str, char& ret)
{
	if(str.empty())
		return false;
	int n = str.size();
	map<char,int> hash;
	for(int i = 0; i < n; i++)
		hash[str[i]]++;
	for(int i = 0; i < n; i++)
		if(hash.count(str[i]) && hash[str[i]] == 1)
		{
			ret = str[i];
			return true;
		}
	return false;

}


//Only ASCII 
bool findOnce(const string& str, char& ret)
{
	if(str.empty())
		return false;
	int n = str.size();
	vector<int> vec(256,0);
	for(int i = 0; i < n; i++)
	{
		int idx = str[i];
		vec[idx]++;
	}
	for(int i = 0; i < n; i++)
	{
		int idx = str[i];
		if(vec[idx] == 1)
		{
			ret = str[i];
			return true;
		}
	}
	return false;
}

