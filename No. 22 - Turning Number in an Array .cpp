#include <iostream>
#include <vector>
using namespace std;

//assuming vec is unimodal array
int findTurning(vector<int>& vec, int start, int end)
{

	if(start == end)
		return vec[start];

	if(start + 1 == end)
		return max(vec[start],vec[end]);

	int mid = start + (end - start)/2;
	if(vec[mid] > vec[mid-1] && vec[mid] > vec[mid+1])
		return vec[mid];
	else if(vec[mid] > vec[mid-1] && vec[mid] < vec[mid+1])
		return findTurning(vec,mid+1,end);
	else
		return findTurning(vec,start,mid-1);
}

