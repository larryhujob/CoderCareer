#include <iostream>
#include <vector>
using namespace std;

int stolenMax(vector<int>& num)
{
	if(num.empty())
		return 0;
	int n = num.size();
	vector<int> vec(n);
	int val1 = num[0];
	if(n == 1)
		return val1;
	int val2 = max(num[0],num[1]);
	if(n == 2)
		return val2;
	for(int i = 2; i < n; i++)
	{
		int tem = max(num[i]+val1, val2);
		val1 = val2;
		val2 = tem;
	}
	return val2;

}

