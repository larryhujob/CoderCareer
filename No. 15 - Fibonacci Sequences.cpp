#include <iostream>
#include <vector>
using namespace std;


//top-down memo
int fibRec(int n, vector<int>& vec)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	if(vec[n] != -1)
		return vec[n];
	vec[n] = fibRec(n-1,vec) + fibRec(n-2,vec);
	return vec[n];
}

int fibCal(int n)
{
	if(n < 0)
		return -1;
	vector<int> vec(n+1,-1);
	return fibRec(n,vec);
}

//bottom-up dp
int fibCal(int n)
{
	vector<int> vec(n+1);
	vec[0] = 0;
	vec[1] = 1;
	for(int i = 2; i <= n; i++)
		vec[i] = vec[i-1] + vec[i-2];
	return vec[n];
}


