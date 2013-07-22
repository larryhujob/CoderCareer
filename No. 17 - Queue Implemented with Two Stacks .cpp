#include <iostream>
#include <stack>
using namespace std;

class CQueue{
public:
	void push(const int& item);
	int pop();

private:
	stack<int> sta1;
	stack<int> sta2;

};

void CQueue::push(const int& item)
{
	sta1.push(item);
}

int CQueue::pop()
{
	if(sta1.empty() && sta2.empty())
		return -1;
	if(sta2.empty())
	{
		while(!sta1.empty())
		{
			int top = sta1.top();
			sta2.push(top);
			sta1.pop();
		}
	}
	int ret = sta2.top();
	sta2.pop();
	return ret;
}
