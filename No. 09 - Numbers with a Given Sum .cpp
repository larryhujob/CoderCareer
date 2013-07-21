#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& vec, int target)
{
	vector<int> ret(2,-1);
	if(vec.empty())
		return ret;
	int n = vec.size();
	int i = 0;
	int j = n-1;
	while(i < j)
	{
		int total = vec[i] + vec[j];
		if(total == target)
		{
			ret[0] = vec[i];
			ret[1] = vec[j];
			return ret;
		}
		else if(total > target)
			j--;
		else i++;

	}
	return ret;

}
