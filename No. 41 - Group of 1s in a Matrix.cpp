#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

//DFS
typedef pair<int,int> Pair;
void countGroupRec(vector<vector<int> >& matrix, int row, int col, int m, int n, set<Pair>& hash)
{
	if(row >= 0 && row < m && col >= 0 && col < n)
	{
		if(hash.count(Pair(row,col)))
			return;
		if(matrix[row][col] == 1)
		{
			hash.insert(Pair(row,col));
			countGroupRec(matrix,row+1,col,m,n,hash);
			countGroupRec(matrix,row-1,col,m,n,hash);
			countGroupRec(matrix,row,col+1,m,n,hash);
			countGroupRec(matrix,row,col-1,m,n,hash);
		}

	}
}

int countGroup(vector<vector<int> >& matrix)
{
	if(matrix.empty())
		return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	int total = 0;
	set<Pair> hash;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			if(matrix[i][j] == 1 && !hash.count(Pair(i,j)) )
			{
				total++;
				countGroupRec(matrix,i,j,m,n,hash);
			}

		}
	return total;
}

//BFS
typedef pair<int,int> Pair;

bool isValid(int row, int col, int m, int n)
{
	return row >= 0 &&  row < m && col >= 0 && col < n;
}

int countGroup(vector<vector<int> >& matrix)
{
	if(matrix.empty())
		return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	queue<Pair> que;
	set<Pair> hash;
	int total = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			
			if(!hash.count(Pair(i,j)) && matrix[i][j] == 1)
			{
				total++;
				que.push(Pair(i,j));
				while(!que.empty())
				{
					Pair top = que.front();
					int row = top.first;
					int col = top.second;
					hash.insert(Pair(row,col));
					que.pop();
					if(isValid(row+1,col,m,n) && !hash.count(Pair(row+1,col)) && matrix[row+1][col] == 1)
						que.push(Pair(row+1,col));
					if(isValid(row-1,col,m,n) && !hash.count(Pair(row-1,col)) && matrix[row-1][col] == 1)
						que.push(Pair(row-1,col));
					if(isValid(row,col+1,m,n) && !hash.count(Pair(row,col+1)) && matrix[row][col+1] == 1)
						que.push(Pair(row,col+1));
					if(isValid(row,col-1,m,n) && !hash.count(Pair(row,col-1)) && matrix[row][col-1] == 1)
						que.push(Pair(row,col-1));
				}
			}
		}
	return total;
}

