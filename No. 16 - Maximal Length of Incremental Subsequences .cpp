#include <iostream>
#include <vector>
using namespace std;

int getLength(vector<int>& num)
{
	if(num.empty())
		return 0;
	int n = num.size();
	vector<int> vec(n);
	vec[0] = 1;
	for(int i = 1; i < n; i++)
	{
		int maxVal = 0;
		for(int j = 0; j < i; j++)
			if(num[i] >= num[j] && vec[j] > maxVal)
				maxVal = vec[j];
		vec[i] = maxVal + 1;
	}
	int len = 0;
	for(int i = 0; i < n; i++)
		len = max(len,vec[i]);
	return len;
}
