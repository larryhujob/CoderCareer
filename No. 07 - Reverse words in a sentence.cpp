#include <iostream>
#include <string>
using namespace std;


void reverseWord(string& str, int i, int j)
{
	while(i < j)
	{
		char tem = str[i];
		str[i] = str[j];
		str[j] = tem;
		i++;
		j--;
	}
}

void reverseSentence(string& str)
{
	if(str.empty())
		return;
	int n = str.size();
	bool inword = false;
	int start = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == n-1 && str[i] != ' ')
			reverseWord(str,start,i);
		if(str[i] == ' ' && inword)
		{
			inword = false;
			reverseWord(str,start,i-1);
		}
		if(str[i] != ' ' && !inword)
		{
			inword = true;
			start = i;
		}
	}
	reverseWord(str,0,n-1);
}

