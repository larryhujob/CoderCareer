#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

bool isPopSeqValid(vector<int>& seq1, vector<int>& seq2)
{
	if(seq1.empty() || seq2.empty())
		return false;
	int m = seq1.size();
	int n = seq2.size();
	if(m != n)
		return false;
	stack<int> sta;
	int i = 0;
	int j = 0;
	while(j < n)
	{
		while(i < n && seq1[i] != seq2[j])
		{
			sta.push(seq1[i]);
			i++;
		}
		if(i == n)
			return false;
		i++;
		j++;
		while(!sta.empty() && sta.top() == seq2[j])
		{
			sta.pop();
			j++;
		}
	}
	return true;
}

//below are test functions
//generate all possible stack pop sequence
void generate(vector<vector<int> >& ret, vector<int>& vec, vector<int>& sta, int n, int num)
{
	if(vec.size() == n)
	{
		ret.push_back(vec);
		return;
	}
	if(num != n+1)
	{
		sta.push_back(num);
		generate(ret,vec,sta,n,num+1);
		sta.pop_back();
	}
	if(!sta.empty())
	{
		int top = sta.back();
		sta.pop_back();
		vec.push_back(top);
		generate(ret,vec,sta,n,num);
		vec.pop_back();
		sta.push_back(top);

	}

}

//generate all permutation
void swap(vector<int>& num, int i, int j)
{
	int tem = num[i];
	num[i] = num[j];
	num[j] = tem;

}
void permutation(vector<vector<int> >& ret, vector<int>& num, int start, int end)
{
	if(start > end)
	{
		ret.push_back(num);
		return;
	}
	permutation(ret,num,start+1,end);
	for(int i = start+1; i <= end; i++)
	{
		swap(num,start,i);
		permutation(ret,num,start+1,end);
		swap(num,start,i);
	}

}
int main()
{
	int a[] = {1,2,3,4,5,6};
	int n = sizeof(a)/sizeof(*a);
	vector<int> seq(&a[0],&a[0]+n);
	vector<int> vec;
	vector<int> sta;
	vector<vector<int> > ret1;
	generate(ret1,vec,sta,n,1);
	vector<vector<int> > ret2;
	permutation(ret2,seq,0,n-1);

	set<vector<int> > hash;
	for(int i = 0; i < ret1.size(); i++)
		hash.insert(ret1[i]);
	for(int i = 0; i < ret2.size(); i++)
		if(!hash.count(ret2[i]))
			cout<<isPopSeqValid(seq,ret2[i]);
	for(int i = 0; i < ret1.size(); i++)
		cout<<isPopSeqValid(seq,ret1[i]);

	return 0;
}