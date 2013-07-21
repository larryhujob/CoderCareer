#include <iostream>
#include <vector>
using namespace std;

bool isPostSeq(vector<int>& vec, int start, int end)
{
	if(start > end)
		return true;
	int rootVal = vec[end];
	int i = start;
	while(i <= end-1 && vec[i] <= rootVal)
		i++;
	int j = i;
	while(i <= end-1)
	{
		if(vec[i] < rootVal)
			return false;
		i++;
	}
	return isPostSeq(vec,start,j-1) && isPostSeq(vec,j,end-1);

}

