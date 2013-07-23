#include <iostream>
#include <vector>
using namespace std;


int findMissing(vector<int>& vec)
{
	if(vec.empty())
		return -1;
	int n = vec.size()+1;
	int total = 0;
	for(int i = 0; i < n-1; i++)
		total += (i - vec[i]);
	total += n-1;
	return total;

}

int findMissing(vector<int>& vec)
{
	if(vec.empty())
		return -1;
	int n = vec.size()+1;
	int total = 0;
	for(int i = 0; i < n-1; i++)
	{
		total ^= i;
		total ^= vec[i];
	}
	total ^= n-1;
	return total;
}



int findSortedMissing(vector<int>& vec, int start, int end)
{
	if(start == end)
	{
		if(vec[start] == start)
			return vec[start] + 1;
		else return vec[start] - 1;
	}

	int mid = start + (end - start) / 2;
	if(vec[mid] == mid)
		return findSortedMissing(vec,mid+1,end);
	else return findSortedMissing(vec,start,mid-1);

}

