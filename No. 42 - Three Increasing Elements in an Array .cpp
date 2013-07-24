#include <iostream>
#include <vector>
using namespace std;

vector<int> findThree(vector<int>& vec)
{
	vector<int> ret(3);
	if(vec.empty())
		return ret;
	int n = vec.size();
	vector<int> left(n);
	int minVal = vec[0];
	for(int i = 0; i < n; i++)
	{
		left[i] = minVal;
		minVal = min(vec[i],minVal);
	}
	vector<int> right(n);
	int maxVal = vec[n-1];
	for(int i = n-1; i >= 0; i--)
	{
		right[i] = maxVal;
		maxVal = max(vec[i],maxVal);
	}
	for(int i = 0; i < n; i++)
	{
		if(vec[i] > left[i] && vec[i] < right[i])
		{
			ret[0] = left[i];
			ret[1] = vec[i];
			ret[2] = right[i];
			return ret;
		}
	}
	return ret;
}
