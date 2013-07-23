#include <iostream>
#include <vector>
using namespace std;

int minCoinChange(vector<int>& num, int n)
{
	if(num.empty())
		return 0;
	int m = num.size()-1;
	vector<int> vec(n+1);
	vec[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int minVal = INT_MAX;
		for(int j = 0; j <= m; j++)
		{
			if(num[j] <= i && (vec[i-num[j]] + 1) < minVal)
				minVal = vec[i-num[j]] + 1;
		}
		vec[i] = minVal; 
	}
	return vec[n];

}
