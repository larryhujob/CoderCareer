#include <iostream>
#include <vector>
using namespace std;


int findMaxDif(vector<int>& vec)
{
	if(vec.empty())
		return -1;
	int n = vec.size();
	int minVal = vec[n-1];
	int maxVal = INT_MIN;
	for(int i = n-2; i >= 0; i--)
	{
		maxVal = max(vec[i] - minVal, maxVal);
		minVal = min(minVal,vec[i]);
	}
	return maxVal;
}


int findMaxDifStock(vector<int>& vec)
{
	if(vec.empty())
		return -1;
	int n = vec.size();
	int maxEnd = 0;
	int maxval = 0;
	for(int i = n-2; i >= 1; i--)
	{
		int profit = vec[i]-vec[i+1];
		maxEnd = max(0, maxEnd+profit);
		maxval = max(maxval,maxEnd);
	}
	return maxval;
}

int findMaxDifRec(vector<int>& vec, int start, int end, int& minVal, int& maxVal)
{
	if(start == end)
	{
		minVal = vec[start];
		maxVal = vec[start];
		return 0;
	}
	int mid = start + (end - start) / 2;
	int leftMin;
	int leftMax;
	int leftDif = findMaxDifRec(vec,start,mid,leftMin,leftMax);
	int rightMax;
	int rightMin;
	int rightDif = findMaxDifRec(vec,mid+1,end,rightMin,rightMax);
	minVal = min(leftMin,rightMin);
	maxVal = max(leftMax,rightMax);

	return max(leftMax-rightMin,max(leftDif,rightDif) );
}

